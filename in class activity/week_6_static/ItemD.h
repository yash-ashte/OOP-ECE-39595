#ifndef ITEMD_H_
#define ITEMD_H_

#include "Item.h"

class ItemD : public Item {
public:
    ItemD(int, float);
    ItemD();
    ItemD(const ItemD&);
    virtual ~ItemD();

    void print() override;

    static int getNumberOfItems();

private:
    static int numberOfItemsD;
};

#endif /* ITEMD_H_ */
