#pragma once

#include <iostream>
#include <stack>
#include <iomanip>

#include "State.h"
#include "Character.h"

class CharacterMenuState : public State
{
private:
    Character*& character;
    std::stack<State*>* states;
public:
    CharacterMenuState(Character*& character, std::stack<State*>* states);
    virtual ~CharacterMenuState();

    void printMenu();
    void updateMenu();
    void update();
};
