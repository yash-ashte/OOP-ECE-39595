#include "ItemD.h"
#include <iostream>

int ItemD::numberOfItemsD = 0;

ItemD::ItemD(int i, float p) : Item(i, p) {
    numberOfItemsD++;
}

ItemD::ItemD() : Item() {
    numberOfItemsD++;
}

ItemD::ItemD(const ItemD& itemD) : Item(itemD) {
    numberOfItemsD++;
}

ItemD::~ItemD() {
    numberOfItemsD--;
}

int ItemD::getNumberOfItems() {
    return numberOfItemsD;
}

void ItemD::print() {
    std::cout << "number of ItemD objects: " << numberOfItemsD;
    std::cout << ", ";
    Item::print();
}
