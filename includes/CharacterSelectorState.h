#pragma once

#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>

#include "Character.h"
#include "State.h"

class CharacterSelectorState : public State
{
private:
    std::vector<Character*>* characterList;
    unsigned& activeCharacter;
    std::stack<State*>* states;
public:
    CharacterSelectorState(std::vector<Character*>* characterList, unsigned& activeCharacter, std::stack<State*>* states);
    virtual ~CharacterSelectorState();

    void printMenu();
    void updateMenu();
    void update();
};
