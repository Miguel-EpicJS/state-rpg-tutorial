#include "../includes/Item.h"

void Item::generate()
{

}

Item::Item(std::string name, unsigned type, unsigned rarity, unsigned value)
{
    this->name = name;
    this->type = type;
    this->rarity = rarity;
    this->value = value;
}

Item::~Item()
{
    
}

const std::string& Item::getName() 
{
    return this->name;
}
const unsigned& Item::getType() 
{
    return this->type;
}
const unsigned& Item::getRarity() 
{
    return this->rarity;
}
const unsigned& Item::getValue() 
{
    return this->value;
}

const std::string Item::toString() const
{
    std::stringstream ss;

    ss << " Name: " << this->name       << 
        " | Type: "     << this->type   << 
        " | Rarity: "   << this->rarity << 
        " | Value: "    << this->value  << "\n";

    return ss.str();
}
