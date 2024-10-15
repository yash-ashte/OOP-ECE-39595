#include <iostream>
#include <vector>

class MyClass {
public:
    int value;
    MyClass(int val) : value(val) {}
    
    void print() const {
        std::cout << "Value: " << value << std::endl;
    }
    
    void mutate(int newValue) {
        value = newValue;
    }
};

void mutateVectorByValue(std::vector<MyClass> vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        vec[i].mutate(100 + i);  
    }
}

void mutateVectorByReference(std::vector<MyClass>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        vec[i].mutate(200 + i);  
    }
}

// Function that takes an array and mutates it
void mutateArray(MyClass arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i].mutate(300 + i);  // Mutate each object
    }
}

int main() {
    // Step 2: Create a vector and populate it with MyClass objects
    std::vector<MyClass> myVec = { MyClass(1), MyClass(2), MyClass(3) };
    
    std::cout << "Original vector contents:" << std::endl;
    for (const auto& obj : myVec) {
        obj.print();
    }

    // Step 3: Pass vector by value and mutate
    mutateVectorByValue(myVec);
    std::cout << "\nAfter passing vector by value (deep copy):" << std::endl;
    for (const auto& obj : myVec) {
        obj.print();  // The vector should remain unchanged (deep copy)
    }

    // Step 4: Pass vector by reference and mutate
    mutateVectorByReference(myVec);
    std::cout << "\nAfter passing vector by reference:" << std::endl;
    for (const auto& obj : myVec) {
        obj.print();  // The vector should be changed (reference)
    }

    // Step 5: Use array and mutate
    MyClass myArray[] = { MyClass(4), MyClass(5), MyClass(6) };
    mutateArray(myArray, 3);
    std::cout << "\nAfter passing array:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        myArray[i].print();  // The array should be changed (arrays decay to pointers)
    }

    return 0;
}
