#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>

#include "./GameState.h"
#include "./CharacterCreatorState.h"
#include "./CharacterSelectorState.h"

class MainMenuState : public State
{
private:
    std::vector<Character*>* characterList;
    unsigned& activeCharacter;
    std::stack<State* >* states;
public:
    MainMenuState(std::vector<Character*>* characterList, unsigned& activeCharacter, std::stack<State*> * states);
    virtual ~MainMenuState();

    void printMenu();
    void updateMenu();
    void update();
};

