#include <iostream>
#include <vector>
#include <string>
#include <list>

class IncrementK {
    private:
        int k;
    public:
        IncrementK(int k_) :k(k_) {};
        void operator()(int& a){a += k; };
};

template <typename iter, typename func>
void my_foreach(iter start, iter end, func function) {
    while (start != end)
    {
        function(*start);
        std::cout<< *start << " ";
        ++start;
    }
    std::cout << std::endl;
}

void increment(int& a){
    a += 1;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    my_foreach(vec.begin(), vec.end(), increment);

    my_foreach(vec.begin(), vec.end(), [](int& a){a += 1;});

    
    my_foreach(vec.begin(), vec.end(), IncrementK(3));


}