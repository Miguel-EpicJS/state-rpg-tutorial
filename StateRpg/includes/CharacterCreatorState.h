#pragma once

#include <iomanip>
#include <iostream>
#include <stack>

#include "./State.h"
#include "./Character.h"

class CharacterCreatorState : public State
{
private:
    const unsigned maxCharacter;
    std::vector<Character*>* characterList; 
    unsigned& activeCharacter;
    std::stack<State*>* states;
public:
    CharacterCreatorState(std::vector<Character*>* characterList, unsigned& activeCharacter, std::stack<State*>* states);
    virtual ~CharacterCreatorState();

    void createCharacter();
    void printMenu();
    void updateMenu();
    void update();
};

