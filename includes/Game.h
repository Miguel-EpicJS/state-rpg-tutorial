#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>

#include "MainMenuState.h"

class Game
{
private:
    bool quit;

    unsigned activeCharacter;
    std::stack<State*> states;
    std::vector<Character*> characterList;

public:
    Game();
    virtual ~Game();

    const bool& getQuit() const;
    
    int getChoice() const;
    void printMenu() const;
    void updateMenu();
    void update();
};