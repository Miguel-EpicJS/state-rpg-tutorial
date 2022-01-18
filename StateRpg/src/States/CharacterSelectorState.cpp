#include "../../includes/CharacterSelectorState.h"

CharacterSelectorState::CharacterSelectorState(std::vector<Character *> *characterList, unsigned &activeCharacter, std::stack<State *> *states)
    : State(),
      activeCharacter(activeCharacter),
      characterList(characterList),
      states(states)
{
}

CharacterSelectorState::~CharacterSelectorState()
{
}

void CharacterSelectorState::printMenu()
{
    std::cout << "=== Character Selector === \n\n";
    std::cout << "(-1) Back to menu\n";

    if (!this->characterList->empty())
    {
        for (size_t i = 0; i < this->characterList->size(); i++)
        {
            std::cout << " (" << i << ") " << this->characterList->at(i)->getMenuBar() << "\n";
        }
        std::cout << "\n";
    }
    
}

void CharacterSelectorState::updateMenu()
{


    if (!this->characterList->empty())
    {
        /* code */

        int choice = this->getChoice();
        if (choice < 0)
        {
            this->setQuit(true);
        }
        else if (choice >= 0 && choice < this->characterList->size())
        {
            this->activeCharacter = choice;
            std::cout << " Character " << choice << " selected.\n\n";
            this->setQuit(true);
        }
        else
        {
            std::cout << " Error: Choice out of bounds!\n\n ";
        }
    }
    else
    {
        this->setQuit(true);
        std::cout << " No characters created!\n";
    }
}

void CharacterSelectorState::update()
{
    this->printMenu();

    this->updateMenu();
}