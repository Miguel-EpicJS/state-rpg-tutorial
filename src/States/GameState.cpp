#include "../../includes/GameState.h"

GameState::GameState(Character *&character, std::stack<State *> *states) : character(character), State()
{
    this->states = states;
}

GameState::~GameState()
{
}

void GameState::combatTest()
{
    Enemy enemy(this->character->getLevel() + 5);
    bool end_combat = false;

    while (!end_combat)
    {

        float hitRating = static_cast<float>(this->character->getHitChance());
        float defence = static_cast<float>(enemy.getDefence());
        float totalHitDef = hitRating + defence;

        float hitPercent = 100.f * (hitRating / totalHitDef) + 10;
        float defPercent = 100.f * (defence / totalHitDef) - 10;

        int random = rand() % 100 + 1;

        std::cout << "----------------------------------------------------------------\n";
        std::cout << "Total: " << totalHitDef << "\n";
        std::cout << "Hit rating: " << hitRating << " Percent: " << hitPercent << "\n";
        std::cout << "Defence: " << defence << " Defence Percent: " << defPercent << "\n";
        std::cout << "Player Damage: " << this->character->getDamageMin() << " - " << this->character->getDamageMax() << "\n";
        std::cout << "Enemy Damage: " << enemy.getDamageMin() << " - " << enemy.getDamageMax() << "\n";
        std::cout << "Random number: " << random << "\n";
        std::cout << "----------------------------------------------------------------\n";

        if (random > 0 && random <= hitPercent)
        {
            int damage = rand()% (this->character->getDamageMax()) + (this->character->getDamageMin());
            enemy.takeDamage(damage);
            std::cout << "YOU HIT THE ENEMY " << "(" << enemy.getHP() << "/" << enemy.getMaxHP() << ")" << " FOR " << damage << "!" << "\n";
        }
        else
        {
            std::cout << "YOU MISSED THE ENEMY!\n";
        }

        if (this->character->getIsDead())
        {
            end_combat = true;
            std::cout << "YOU ARE DEAD AND LOST SOME EXP AND SPIRIT STONES\n";
        }
        else if (enemy.getIsDead())
        {
            end_combat = true;
            int gainExp = rand()%(enemy.getLevel() * 10) + 1;
            std::cout << "YOU DEAFEATED THE ENEMY AND GAINED " << gainExp << " EXP!\n";
            this->character->addExp(gainExp);
        }
    }
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
              << " (4) Reset Menu "
              << "\n\n"
              << " (5) Combat Test "
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

        break;
    case 5:
        this->combatTest();
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