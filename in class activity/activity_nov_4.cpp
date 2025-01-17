#include <iostream>
#include <vector>
#include <algorithm>

struct IncrementK {
    int k;
    IncrementK(int increment) : k(increment) {}

    void operator()(int &value) const {
        value += k;
    }
};

template <typename Iterator, typename Func>
void my_foreach(Iterator start, Iterator end, Func func) {
    while (start != end) {
        func(*start);
        ++start;
    }
}

void Increment(int &value) {
    value += 1;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    my_foreach(vec.begin(), vec.end(), Increment);

    for (const auto &val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl; 

    my_foreach(vec.begin(), vec.end(), [](int &value) { value += 1; });

    for (const auto &val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    my_foreach(vec.begin(), vec.end(), IncrementK(3));

    for (const auto &val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}

