#include <iostream>
#include <vector>

int main() {
    // Declare and populate the vector
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // Iterate through the vector and print out its contents
    std::cout << "Vector contents: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Accessing valid memory location
    std::cout << "Accessing valid memory location: " << vec[2] << std::endl;

    // Attempting to access invalid memory location using vec[...]
    std::cout << "Accessing invalid memory location using vec[5]: " << vec[5] << std::endl;  // Out of bounds access

    // Attempting to access invalid memory location using vec.at(...)
    try {
        std::cout << "Accessing invalid memory location using vec.at(5): " << vec.at(5) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
