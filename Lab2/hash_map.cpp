#include "hash_map.h"

hash_map::hash_map(size_t capacity) : _size(0), _capacity(capacity) {
    _head = new hash_list[_capacity];  
}

hash_map::hash_map(const hash_map &other) : _size(other._size), _capacity(other._capacity) {
    _head = new hash_list[_capacity];
    for (size_t i = 0; i < _capacity; ++i) {
        _head[i] = other._head[i]; 
    }
}

hash_map &hash_map::operator=(const hash_map &other) {
    if (this == &other) {
        return *this; 
    }

    delete[] _head;  

    _capacity = other._capacity;
    _size = other._size;
    _head = new hash_list[_capacity];

    for (size_t i = 0; i < _capacity; ++i) {
        _head[i] = other._head[i];  
    }

    return *this;
}

void hash_map::insert(int key, float value) {
    size_t index = abs(key) % _capacity;  
    size_t previous_size = _head[index].get_size();

    _head[index].insert(key, value); 

    if (_head[index].get_size() > previous_size) {
        _size++;  
    }
}

std::optional<float> hash_map::get_value(int key) const {
    size_t index = abs(key) % _capacity;  
    return _head[index].get_value(key);  
}

bool hash_map::remove(int key) {
    size_t index = abs(key) % _capacity;  
    bool removed = _head[index].remove(key);

    if (removed) {
        _size--;  
    }
    return removed;
}

size_t hash_map::get_size() const {
    return _size;
}

size_t hash_map::get_capacity() const {
    return _capacity;
}

void hash_map::get_all_keys(int *keys) {
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

void hash_map::get_bucket_sizes(size_t *buckets) {
    for (size_t i = 0; i < _capacity; ++i) {
        buckets[i] = _head[i].get_size();  
    }
}

hash_map::~hash_map() {
    delete[] _head;  
}
