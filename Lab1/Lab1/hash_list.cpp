#include "hash_list.h"
#include <iostream>

hash_list::hash_list() : size(0), head(nullptr), iter_ptr(nullptr) {}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) {

    //std::cout << "in" << size;
    if (head == nullptr) {
        node* newnode = new node;
        head = newnode;
        newnode->key = key;
        newnode->value = value;
        newnode->next = nullptr;
        size = size + 1;
      //  std::cout << "head" << size;
        return;
    }
    node* cur = head;
    while (cur->key != key && cur->next != nullptr){
        cur = cur->next;
    }
    if (cur->key == key){
        cur->value = value;
    }
    else{
        node* newnode = new node;
        newnode->key = key;
        newnode->value = value;
        newnode->next = nullptr;
        cur->next = newnode;
        size = size + 1;
    }
    //std::cout << "end" << size;
    return;
}


std::optional<float> hash_list::get_value(int key) const { 
    node* curr = head;
    int val;
    while (curr && curr->key != key && curr->next != NULL) {
        curr = curr->next;
    }
    if (curr && curr->key == key){
        val = curr->value;
        return val;
    }
    return std::nullopt; 
}

bool hash_list::remove(int key) { 
    node* curr = head;
    node* prev = nullptr;
    while (curr && curr->key != key && curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    if (curr && curr->key == key) {
        if (prev != nullptr){
            prev ->next = curr->next;
        }
        else {
            head = curr->next;
        }
        delete curr;
        size = size - 1;
        //std::cout<<head->key<<std::endl;
        return true;
    }
    return false;
}

size_t hash_list::get_size() const { 
    return size;    
}

hash_list::~hash_list() {
    node* current = head;
    while (current != nullptr) {
        node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;    
}

/**-----------------------------------------------------------------------------------
 * END Part 1
 *------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------
 * START Part 2
 *------------------------------------------------------------------------------------*/

hash_list::hash_list(const hash_list &other) {
    if (other.head == nullptr){
        head = nullptr;
        size = 0;
        return;
    }
    size = 0;
    head = new node;
    head->key = other.head->key;
    head->value = other.head->value;
    head->next = nullptr;
    size++;

    node* curr = other.head->next;
    node* copy = head;

    while (curr != nullptr)
    {
        copy->next = new node;
        copy = copy->next;
        copy->key = curr->key;
        copy->value = curr->value;
        copy->next = nullptr;
        curr = curr->next;
        size++;
    }
    
}

hash_list &hash_list::operator=(const hash_list &other) {
    if (this == &other) {
        size = other.size;
        return *this;
        
    }
    node* current = head;
    head = nullptr;
    while (current != nullptr)
    {
        node* temp = current->next;
        delete current;
        size--;
        current = temp;
    }

    if (other.head == nullptr){
        //head = nullptr;
        size = 0;
        return *this;
    }
    head = new node;
    head->key = other.head->key;
    head->value = other.head->value;
    head->next = nullptr;
    size++;

    node* curr = other.head->next;
    node* copy = head;

    while (curr != nullptr)
    {
        copy->next = new node;
        copy = copy->next;
        copy->key = curr->key;
        copy->value = curr->value;
        copy->next = nullptr;
        curr = curr->next;
        size++;
    }


    return *this;
}

void hash_list::reset_iter() {
    iter_ptr = head;
}


void hash_list::increment_iter() {
    if (iter_ptr->next)
    {
        iter_ptr = iter_ptr->next;
    }
    else {
        iter_ptr = nullptr;
    }
}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { 



    if (iter_ptr == nullptr) {
        return std::nullopt;  // Return an empty optional if the iterator is NULL
    }

    // Return a pair containing pointers to the key and value of the current node
     return std::optional<std::pair<const int *, float *>>(
       {&(iter_ptr->key), &(iter_ptr->value)}
    );

    
}


bool hash_list::iter_at_end() {
    if (iter_ptr == nullptr)
    {
        return true;
    }
    
     return false;
}
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
