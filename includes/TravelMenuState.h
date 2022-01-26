#pragma once 

#include "CombatState.h"

enum encounters { EMPTY = 0, FARM, CITY, SHOP, CHEST};

class TravelMenuState : public State
{
private:
    Character*& character;
    std::stack<State*>* states;
    std::string locationString;
    std::string minimapString;
    int nrOfLocations;

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