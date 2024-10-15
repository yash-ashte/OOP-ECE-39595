#include "hash_map.hpp"
//#include "hash_list.hpp"
#include <iostream>
#include <optional>

void test_hash_map() {
    // Create a hash_map with capacity of 10, upper load factor of 0.75, and lower load factor of 0.25
    hash_map<int, float> my_map(10, 0.75, 0.25);

    // Test insert
    std::cout << "Inserting values..." << std::endl;
    my_map.insert(1, 1.1);
    my_map.insert(2, 2.2);
    my_map.insert(3, 3.3);
    my_map.insert(4, 4.4);
    std::cout << "Past Insert" << std::endl;

    // Test get_value
    std::optional<float> value = my_map.get_value(2);
    if (value) {
        std::cout << "Key 2 has value: " << *value << std::endl;
    } else {
        std::cout << "Key 2 not found." << std::endl;
    }

    // Test remove
    std::cout << "Removing key 3..." << std::endl;
    bool removed = my_map.remove(3);
    if (removed) {
        std::cout << "Key 3 removed successfully." << std::endl;
    } else {
        std::cout << "Key 3 not found." << std::endl;
    }

    // Test get_value after removal
    value = my_map.get_value(3);
    if (value) {
        std::cout << "Key 3 has value: " << *value << std::endl;
    } else {
        std::cout << "Key 3 not found." << std::endl;
    }

    // Test size
    std::cout << "Map size: " << my_map.get_size() << std::endl;

    // Test rehashing by inserting more values to exceed upper load factor
    std::cout << "Inserting more values to trigger rehash..." << std::endl;
    for (int i = 5; i < 15; ++i) {
        my_map.insert(i, static_cast<float>(i) + 0.1);
    }

    // Check the map size after rehashing
    std::cout << "Map size after rehashing: " << my_map.get_size() << std::endl;

    // Test get_all_keys
    std::cout << "Getting all keys in the map..." << std::endl;
    int* keys = new int[my_map.get_size()];
    my_map.get_all_keys(keys);
    for (size_t i = 0; i < my_map.get_size(); ++i) {
        std::cout << "Key: " << keys[i] << std::endl;
    }
    delete[] keys;

    // Test get_all_sorted_keys
    std::cout << "Getting all sorted keys in the map..." << std::endl;
    int* sorted_keys = new int[my_map.get_size()];
    my_map.get_all_sorted_keys(sorted_keys);
    for (size_t i = 0; i < my_map.get_size(); ++i) {
        std::cout << "Sorted Key: " << sorted_keys[i] << std::endl;
    }
    delete[] sorted_keys;

    // Test get_bucket_sizes
    std::cout << "Getting bucket sizes..." << std::endl;
    size_t* buckets = new size_t[my_map.get_capacity()];
    my_map.get_bucket_sizes(buckets);
    for (size_t i = 0; i < my_map.get_capacity(); ++i) {
        std::cout << "Bucket " << i << " size: " << buckets[i] << std::endl;
    }
    delete[] buckets;
}

int main() {
    std::cout << "Testing hash_map..." << std::endl;
    test_hash_map();

    std::cout << "Tests completed." << std::endl;
    return 0;
}
