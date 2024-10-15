#include "hash_map.h"

template <typename K, typename V>
hash_map<K, V>::hash_map(size_t capacity) : _size(0), _capacity(capacity) {
    _head = new hash_list<K, V>[_capacity];
}

template <typename K, typename V>
hash_map<K, V>::hash_map(const hash_map &other) : _size(other._size), _capacity(other._capacity) {
    _head = new hash_list<K, V>[_capacity];
    for (size_t i = 0; i < _capacity; ++i) {
        _head[i] = other._head[i];
    }
}

template <typename K, typename V>
hash_map<K, V> &hash_map<K, V>::operator=(const hash_map &other) {
    if (this == &other) {
        return *this;
    }

    delete[] _head;
    _capacity = other._capacity;
    _size = other._size;
    _head = new hash_list<K, V>[_capacity];

    for (size_t i = 0; i < _capacity; ++i) {
        _head[i] = other._head[i];
    }

    return *this;
}

template <typename K, typename V>
hash_map<K, V>::hash_map(size_t capacity, double upper_load_factor, double lower_load_factor)
    : _size(0), _capacity(get_next_capacity(capacity, true)), // Start with the next valid capacity
      _upper_load_factor(upper_load_factor), _lower_load_factor(lower_load_factor) {
    _head = new hash_list<K, V>[_capacity];
}

template <typename K, typename V>
void hash_map<K, V>::insert(K key, V value) {
    static_assert(noexcept(_hash(key)), "Hash function must be noexcept.");
    
    size_t index = _hash(key) % _capacity;
    size_t previous_size = _head[index].get_size();

    _head[index].insert(key, value);

    if (_head[index].get_size() > previous_size) {
        _size++;
    }

    // Check for rehashing
    if (need_to_rehash()) {
        size_t new_capacity = (_size > _upper_load_factor * _capacity) ? _capacity * 2 : _capacity / 2;
        rehash(new_capacity);
    }
}

template <typename K, typename V>
void hash_map<K, V>::get_all_sorted_keys(K *keys) const {
    std::vector<K> key_vec;

    // Collect all keys from each bucket
    for (size_t i = 0; i < _capacity; ++i) {
        _head[i].reset_iter();
        while (!_head[i].iter_at_end()) {
            auto iter_value = _head[i].get_iter_value();
            if (iter_value) {
                key_vec.push_back(*(iter_value->first));
            }
            _head[i].increment_iter();
        }
    }

    // Sort the keys
    std::sort(key_vec.begin(), key_vec.end());

    // Copy sorted keys into the provided array
    for (size_t i = 0; i < key_vec.size(); ++i) {
        keys[i] = key_vec[i];
    }
}


template <typename K, typename V>
std::optional<V> hash_map<K, V>::get_value(K key) const {
    size_t index = _hash(key) % _capacity;
    return _head[index].get_value(key);
}

template <typename K, typename V>
bool hash_map<K, V>::remove(K key) {
    size_t index = _hash(key) % _capacity;
    bool removed = _head[index].remove(key);

    if (removed) {
        _size--;
    }
    return removed;
}

template <typename K, typename V>
size_t hash_map<K, V>::get_size() const {
    return _size;
}

template <typename K, typename V>
size_t hash_map<K, V>::get_capacity() const {
    return _capacity;
}

template <typename K, typename V>
void hash_map<K, V>::get_all_keys(K *keys) {
    size_t key_index = 0;
    for (size_t i = 0; i < _capacity; ++i) {
        _head[i].reset_iter();
        while (!_head[i].iter_at_end()) {
            auto iter_value = _head[i].get_iter_value();
            if (iter_value) {
                keys[key_index++] = *(iter_value->first);
            }
            _head[i].increment_iter();
        }
    }
}

template <typename K, typename V>
void hash_map<K, V>::get_bucket_sizes(size_t *buckets) {
    for (size_t i = 0; i < _capacity; ++i) {
        buckets[i] = _head[i].get_size();
    }
}

template <typename K, typename V>
hash_map<K, V>::~hash_map() {
    delete[] _head;
}

template <typename K, typename V>
void hash_map<K, V>::rehash(size_t new_capacity) {
    new_capacity = get_next_capacity(new_capacity, new_capacity > _capacity); // Ensure capacity is valid

    hash_list<K, V> *new_head = new hash_list<K, V>[new_capacity];

    for (size_t i = 0; i < _capacity; ++i) {
        _head[i].reset_iter();
        while (!_head[i].iter_at_end()) {
            auto iter_value = _head[i].get_iter_value();
            if (iter_value) {
                size_t new_index = _hash(*(iter_value->first)) % new_capacity;
                new_head[new_index].insert(*(iter_value->first), *(iter_value->second));
            }
            _head[i].increment_iter();
        }
    }

    delete[] _head;
    _head = new_head;
    _capacity = new_capacity;
}
    
template <typename K, typename V>
bool hash_map<K, V>::need_to_rehash() {
    double load_factor = static_cast<double>(_size) / _capacity;
    return (load_factor > _upper_load_factor && _capacity < CAPACITIES[sizeof(CAPACITIES)/sizeof(CAPACITIES[0]) - 1]) ||
           (load_factor < _lower_load_factor && _capacity > CAPACITIES[0]);
}

template <typename K, typename V>
size_t hash_map<K, V>::get_next_capacity(size_t current_capacity, bool increase) {
    size_t new_capacity = current_capacity;

    if (increase) {
        // Find the next larger capacity in the predefined list
        for (size_t cap : CAPACITIES) {
            if (cap > current_capacity) {
                new_capacity = cap;
                break;
            }
        }
    } else {
        // Find the next smaller capacity in the predefined list
        for (int i = sizeof(CAPACITIES)/sizeof(CAPACITIES[0]) - 1; i >= 0; --i) {
            if (CAPACITIES[i] < current_capacity) {
                new_capacity = CAPACITIES[i];
                break;
            }
        }
    }

    return new_capacity;
}

