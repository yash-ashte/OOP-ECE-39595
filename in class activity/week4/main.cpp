#include <iostream>
#include <string>
#include <limits>
#include "complex.h"
//#include "Obj.h"

int minArray(const int* array, int length) {
    int min = array[0];
    for (int i = 1; i < length; i++){
        if (array[i] < min){
            min = array[i];
        }
    }
    return min;
}

template <typename T> T minArray(const T* array, int length){
    T min = array[0];
    for (int i = 1; i < length; i++){
        if (array[i] < min){
            min = array[i];
        }
    }
    return min;
}

int main(int argc, char* argv[ ]) {
    int array[] = {5,4,1,2,9};
    char c_array[] = {'a','b','c','d','e'};
    float f_array[] = {1.9,1.1,1.2,1.3,1.4};
    std::string s_array[] = {"abc","def","jhk","yash","idk"};

    int min = minArray(array, 5);
    std::cout<<min<<std::endl;

    int min_i = minArray(array, 5);
    char min_c = minArray(c_array, 5);
    float min_f = minArray(f_array, 5);
    std::string min_s = minArray(s_array, 5);
    std::cout<<min_i<<std::endl;
    std::cout<<min_c<<std::endl;
    std::cout<<min_f<<std::endl;
    std::cout<<min_s<<std::endl;

    int real[] = {1,2,3,4,5};
    int img[] = {1,2,3,4,5};

    complex* comp_array = new complex[5];

    for (int i = 0; i < 5; i++) {
        comp_array[i] = complex(real[i],img[i]);
    }

}