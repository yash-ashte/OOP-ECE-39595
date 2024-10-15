#include "hash_list.h"
#include <iostream>

template <typename K, typename V>
hash_list<K, V>::hash_list() : size(0), head(nullptr), iter_ptr(nullptr) {}

template <typename K, typename V>
void hash_list<K, V>::insert(K key, V value) {
    if (head == nullptr) {
        node<K, V> *newnode = new node<K, V>;
        head = newnode;
        newnode->key = key;
        newnode->value = value;
        newnode->next = nullptr;
        size++;
        return;
    }
    node<K, V> *cur = head;
    while (cur->key != key && cur->next != nullptr) {
        cur = cur->next;
    }
    if (cur->key == key) {
        cur->value = value;
    } else {
        node<K, V> *newnode = new node<K, V>;
        newnode->key = key;
        newnode->value = value;
        newnode->next = nullptr;
        cur->next = newnode;
        size++;
    }
}

template <typename K, typename V>
std::optional<V> hash_list<K, V>::get_value(K key) const {
    node<K, V> *curr = head;
    while (curr && curr->key != key && curr->next != nullptr) {
        curr = curr->next;
    }
    if (curr && curr->key == key) {
        return curr->value;
    }
    return std::nullopt;
}

template <typename K, typename V>
bool hash_list<K, V>::remove(K key) {
    node<K, V> *curr = head;
    node<K, V> *prev = nullptr;
    while (curr && curr->key != key && curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }
    if (curr && curr->key == key) {
        if (prev != nullptr) {
            prev->next = curr->next;
        } else {
            head = curr->next;
        }
        delete curr;
        size--;
        return true;
    }
    return false;
}

template <typename K, typename V>
size_t hash_list<K, V>::get_size() const {
    return size;
}

template <typename K, typename V>
hash_list<K, V>::~hash_list() {
    node<K, V> *current = head;
    while (current != nullptr) {
        node<K, V> *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

template <typename K, typename V>
hash_list<K, V>::hash_list(const hash_list &other) {
    if (other.head == nullptr) {
        head = nullptr;
        size = 0;
        return;
    }
    size = 0;
    head = new node<K, V>;
    head->key = other.head->key;
    head->value = other.head->value;
    head->next = nullptr;
    size++;

    node<K, V> *curr = other.head->next;
    node<K, V> *copy = head;

    while (curr != nullptr) {
        copy->next = new node<K, V>;
        copy = copy->next;
        copy->key = curr->key;
        copy->value = curr->value;
        copy->next = nullptr;
        curr = curr->next;
        size++;
    }
}

template <typename K, typename V>
hash_list<K, V> &hash_list<K, V>::operator=(const hash_list &other) {
    if (this == &other) {
        size = other.size;
        return *this;
    }
    node<K, V> *current = head;
    head = nullptr;
    while (current != nullptr) {
        node<K, V> *temp = current->next;
        delete current;
        size--;
        current = temp;
    }

    if (other.head == nullptr) {
        size = 0;
        return *this;
    }
    head = new node<K, V>;
    head->key = other.head->key;
    head->value = other.head->value;
    head->next = nullptr;
    size++;

    node<K, V> *curr = other.head->next;
    node<K, V> *copy = head;

    while (curr != nullptr) {
        copy->next = new node<K, V>;
        copy = copy->next;
        copy->key = curr->key;
        copy->value = curr->value;
        copy->next = nullptr;
        curr = curr->next;
        size++;
    }

    return *this;
}

template <typename K, typename V>
void hash_list<K, V>::reset_iter() {
    iter_ptr = head;
}

template <typename K, typename V>
void hash_list<K, V>::increment_iter() {
    if (iter_ptr->next) {
        iter_ptr = iter_ptr->next;
    } else {
        iter_ptr = nullptr;
    }
}

template <typename K, typename V>
std::optional<std::pair<const K *, V *>> hash_list<K, V>::get_iter_value() {
    if (iter_ptr == nullptr) {
        return std::nullopt;
    }
    return std::optional<std::pair<const K *, V *>>({&(iter_ptr->key), &(iter_ptr->value)});
}

template <typename K, typename V>
bool hash_list<K, V>::iter_at_end() {
    return iter_ptr == nullptr;
}
