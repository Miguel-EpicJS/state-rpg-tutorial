#pragma once

#include "Item.h"

class Inventory
{
private:
    Item **items;
public:
    Inventory();
    virtual ~Inventory();
};
