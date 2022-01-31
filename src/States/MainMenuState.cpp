#include "../../includes/MainMenuState.h"

MainMenuState::MainMenuState(std::vector<Character*>* characterList, unsigned& activeCharacter, std::stack<State*> * states) : activeCharacter(activeCharacter), State()
{
    this->states = states;
    this->characterList = characterList;

    this->characterList->push_back(new Character("TEST", "DEBUGGING CHARACTER"));
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::printMenu()
{
    std::cout << "=== Main Menu === \n\n";

    if (!this->characterList->empty())
    {
        std::cout << this->characterList->at(this->activeCharacter)->getMenuBar() << "\n\n"; 
    }    

    std::cout << " (-1) Quit\n"
        << " (1) Start Game\n"
        << " (2) Create Character\n"
        << " (3) Select Character\n\n"
    ;
}

void MainMenuState::updateMenu()
{

    switch (this->getChoice())
    {
    case -1:
        this->setQuit(true);
        break;
    case 1:
        if (!this->characterList->empty())
        {
            this->states->push(new GameState(this->characterList->at(this->activeCharacter), this->states));
        }else {
            std::cout << "Error!, Create a character first!\n";
        }
        
        
        break;
    case 2:
        this->states->push(new CharacterCreatorState(this->characterList, this->activeCharacter, this->states));
        break;
    case 3:
        this->states->push(new CharacterSelectorState(this->characterList, this->activeCharacter, this->states));
        break;
    default:
        std::cout << "Not a valid option! \n\n";
        break;
    }

}

void MainMenuState::update()
{
    this->printMenu();

    this->updateMenu();   
}