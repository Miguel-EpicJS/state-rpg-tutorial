#pragma once


#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>

#include "State.h"
#include "Character.h"
#include "CharacterMenuState.h"
#include "TravelMenuState.h"
#include "Enemy.h"

class GameState : public State
{
private:
    Character*& character;
    
    std::stack<State*>* states;

public:
    GameState(Character*& character, std::stack<State*>* states);
    virtual ~GameState();

    void printMenu() const;
    void updateMenu();
    virtual void update();
};