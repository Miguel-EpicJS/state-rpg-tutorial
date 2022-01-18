#include "../../includes/CharacterCreatorState.h"

CharacterCreatorState::CharacterCreatorState(std::vector<Character *> *characterList, unsigned &activeCharacter, std::stack<State *> *states) : activeCharacter(activeCharacter), State(), maxCharacter(5)
{
    this->characterList = characterList;
    this->states = states;
}

CharacterCreatorState::~CharacterCreatorState()
{
}

void CharacterCreatorState::createCharacter()
{

    if (this->characterList->size() < this->maxCharacter)
    {
        /* code */

        std::string name = "";
        std::string bio = "";

        std::getline(std::cin, name);
        std::cout << "Name: ";
        std::getline(std::cin, name);
 
        std::cout << "Bio: ";
        std::getline(std::cin, bio);
        
        this->characterList->push_back(new Character(name, bio));

        std::cout << "Character " << name << " created.\n\n";
    }else 
    {
        std::cout << "Max number of characters reached!" << "\n";
    }
}

void CharacterCreatorState::printMenu()
{
    std::cout << "=== Character Creator === \n\n"
        << " Characterr: " << std::to_string(this->characterList->size()) << " / " << std::to_string(this->maxCharacter) << "\n\n"
        << " (-1) Back To Menu\n"
        << " (1) New Character\n\n";
}

void CharacterCreatorState::updateMenu()
{

    switch (this->getChoice())
    {
    case -1:
        this->setQuit(true);
        std::cout << "\n\n Quitting main menu state \n\n";
        break;
    case 1:
        createCharacter();
        break;
    default:
        std::cout << "Not a valid option! \n\n";
        break;
    }
}

void CharacterCreatorState::update()
{
    this->printMenu();

    this->updateMenu();
}