#include "../../includes/CharacterMenuState.h"

CharacterMenuState::CharacterMenuState(Character*& character, std::stack<State*>* states) : character(character), State()
{
    this->states = states;
}

CharacterMenuState::~CharacterMenuState()
{
}

void CharacterMenuState::printMenu()
{
    std::cout << " --- Character Menu --- \n\n"
        << this->character->getMenuBar() << "\n\n"
        << " (-1) Back to Menu\n"
        << " (1) Name & Bio \n"
        << " (2) Stats\n"
        << " (3) Level Up\n"
        << " (3) Assign stat points\n"
        ;
}

void CharacterMenuState::updateMenu()
{
    switch (this->getChoice())
    {
    case -1:
        this->setQuit(true);
        break;
    case 1:
        std::cout << this->character->toStringNameBio() << "\n";
        break;
    case 2:
        std::cout << this->character->toStringsStats() << "\n";
        break;
    case 3:
        if (this->character->canLevelUp())
        {
            std::cout << "LEVEL UP - !\n";
        }
        else
        {
            std::cout << "Not enough EXP! - \n";
        }
        break;
    case 4:
        break;
    default:
        std::cout << "Not a valid option! \n\n";
        break;
    }
}

void CharacterMenuState::update() 
{
    this->printMenu();

    this->updateMenu();
}