#include "../../includes/GameState.h"

GameState::GameState(Character *&character, std::stack<State *> *states) : character(character), State()
{
    this->states = states;
}

GameState::~GameState()
{
}

void GameState::printMenu() const
{
    std::cout << " --- GAME MENU ---"
              << "\n\n"
              << this->character->getMenuBar() << "\n"
              << " (-1) Quit to Main Menu "
              << "\n"
              << " (1) Character Menu "
              << "\n"
              << " (2) Shop Menu "
              << "\n"
              << " (3) Travel Menu "
              << "\n"
              << " (4) Rest Menu "
              << "\n\n";
}

void GameState::updateMenu()
{
    switch (this->getChoice() | system("clear"))
    {
    case -1:
        this->setQuit(true);
        break;
    case 1:
        this->states->push(new CharacterMenuState(this->character, this->states));
        break;
    case 2:

        break;
    case 3:
        this->states->push(new TravelMenuState(this->character, this->states));
        break;
    case 4:
        this->character->resetStatus();
        std::cout << "You have rested...";
        break;
    default:
        std::cout << std::setw(7) << "--- No such option in the menu! ---"
                  << "\n";
        break;
    }
}

void GameState::update()
{
    this->printMenu();

    this->updateMenu();
}