#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << "Matrix contents:" << std::endl;
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl; 
    }

    return 0;
}
