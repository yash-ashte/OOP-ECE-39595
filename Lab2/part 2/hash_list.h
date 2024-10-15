#ifndef HASH_LIST_H
#define HASH_LIST_H

#include <optional>
#include <stddef.h>
#include <stdlib.h>

// Forward declaration of node and templated hash_list class
template <typename K, typename V>
struct node {
    K key;
    V value;
    node *next;
};

template <typename K, typename V>
class hash_list {
public:
    hash_list();
    void insert(K key, V value);
    std::optional<V> get_value(K key) const;
    bool remove(K key);
    size_t get_size() const;
    ~hash_list();
    hash_list(const hash_list &other);
    hash_list &operator=(const hash_list &other);
    void reset_iter();
    void increment_iter();
    std::optional<std::pair<const K *, V *>> get_iter_value();
    bool iter_at_end();

private:
    size_t size;
    node<K, V> *head;
    node<K, V> *iter_ptr;
};

// Include implementation
#include "hash_list.hpp"

#endif
