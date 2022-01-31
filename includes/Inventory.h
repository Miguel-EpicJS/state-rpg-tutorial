#pragma once

#include <string>
#include <sstream>

#include "Item.h"

class Inventory
{
private:
    Item **items;
    unsigned cap;
    unsigned nrOfItems;

    void initialize(const unsigned from = 0);
    void expand();

public:
    Inventory(unsigned cap = 10);
    Inventory(const Inventory& other);
    virtual ~Inventory();

    void operator = ( const Inventory& other);
    Item& operator [] (const unsigned index);

    const unsigned& size() const;
    const unsigned& capacity() const;
    Item& at(const unsigned index);

    void add(const Item& item);
    void remove(const unsigned index);

    std::string toString() const;
};
