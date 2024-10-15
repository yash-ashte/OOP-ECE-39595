#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <optional>
#include <stddef.h>
#include <stdlib.h>
#include <functional>
#include <vector>
#include "hash_list.h"

// Predefined list of capacities (must match expected values for tests)
const size_t CAPACITIES[] = {7, 13, 29, 53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317, 196613, 393241, 786433, 1572869, 209};

template <typename K, typename V>
class hash_map {
public:
    hash_map(size_t capacity, double upper_load_factor, double lower_load_factor);
    hash_map(size_t capacity);
    hash_map(const hash_map &other);
    hash_map &operator=(const hash_map &other);
    
    void insert(K key, V value);
    std::optional<V> get_value(K key) const;
    bool remove(K key);
    size_t get_size() const;
    size_t get_capacity() const;
    void get_all_keys(K *keys);
    void get_all_sorted_keys(K *keys) const;
    void get_bucket_sizes(size_t *buckets);
    ~hash_map();

private:
    size_t _size;
    size_t _capacity;
    double _upper_load_factor;
    double _lower_load_factor;
    
    hash_list<K, V> *_head;
    std::hash<K> _hash;

    size_t get_next_capacity(size_t current_capacity, bool increase);
    bool need_to_rehash();
    void rehash(size_t new_capacity);
};

#include "hash_map.hpp"
#endif
