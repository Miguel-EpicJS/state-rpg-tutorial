#pragma once 

#include <iostream>
#include <iomanip>
#include <stack>
#include <ctime>

#include "Character.h"
#include "State.h"

enum encounters { EMPTY = 0, FARM, CITY, SHOP, ENEMY, CHEST};

class TravelMenuState : public State
{
private:
    Character*& character;
    std::stack<State*>* states;
    std::string locationString;
    std::string minimapString;

public:
    TravelMenuState(Character*& character, std::stack<State*>* states);
    virtual ~TravelMenuState();

    //Functions 

    void travel();

    void printMenu();
    void updateEncounterMenu();
    void updateMinimap();
    void updateMenu();
    void update();
};