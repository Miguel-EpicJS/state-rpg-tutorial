#include "../../includes/CombatState.h"

CombatState::CombatState(Character*& character, std::stack<State *>* states) : State(), character(character)
{
    this->states = states;
}

CombatState::~CombatState()
{
}


void CombatState::printMenu()
{
    std::cout << " --- Combat Menu --- \n\n"
        << this->character->getMenuBar() << "\n\n"
        << this->character->toStringPosition() << "\n\n"
        << " (-1) Back to Menu\n"
        << " (1) Begin Combat\n\n";
}

void CombatState::updateMenu()
{
    switch (this->getChoice())
    {
    case -1:
        this->setQuit(true);
        break;
    case 1:
        break;
    default:
        std::cout << "Not a valid option! \n\n";
        break;
    }
}

void CombatState::update()
{
    this->printMenu();
    this->updateMenu();
}
