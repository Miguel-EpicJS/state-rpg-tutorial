#include "../includes/Game.h"

#include <iostream>
int main()
{
    // Game loop

    Game game;



    while (!game.getQuit())
    {
        game.update();        
    }  


    return 0;
}