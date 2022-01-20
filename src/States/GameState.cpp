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
    Enemy enemy(this->character->getLevel());
    bool end_combat = false;

    int turnDice  = rand() % 2;
    int round = 0;

    srand(time(NULL));

    while (!end_combat)
    {
        round++;

        std::string atkStr = "Player";
        std::string defStr = "Enemy";

        float hitRating = static_cast<float>(this->character->getHitChance());
        float defence = static_cast<float>(enemy.getDefence());

        if (!turnDice)
        {
            atkStr = "Enemy";
            defStr = "Player";

            hitRating = static_cast<float>(enemy.getHitChance());
            defence = static_cast<float>(this->character->getDefence());

        }
                
        
        float totalHitDef = hitRating + defence;

        float hitPercent = 100.f * (hitRating / totalHitDef) + 10;
        float defPercent = 100.f * (defence / totalHitDef) - 10;

        int random = rand() % 100 + 1;

        std::cout << "----------------------------------------------------------------\n";
        std::cout << "Attacker: " << atkStr << "\n";
        std::cout << "Defender: " << defStr << "\n";
        std::cout << "Round: " << round << "\n";
        std::cout << "----------------------------------------------------------------\n";

        if (random > 0 && random <= hitPercent)
        {
            int damage = 0;
            
            if (turnDice)
            {
                damage = rand()% (this->character->getDamageMax()) + (this->character->getDamageMin());
                enemy.takeDamage(damage);
            }
            else
            {
                damage = rand()% (enemy.getDamageMax()) + (enemy.getDamageMin());
                this->character->takeDamage(damage);
            }
            
            std::cout << atkStr << " HIT " << defStr << " FOR " << damage << "!" << "\n";
        }
        else
        {
            std::cout << atkStr << " MISSED " << defStr << "\n";
        }

        std::cout << "----------------------------------------------------------------\n";
        std::cout << "Total: " << totalHitDef << "\n";
        std::cout << "Hit rating: " << hitRating << " Percent: " << hitPercent << "\n";
        std::cout << "Defence: " << defence << " Defence Percent: " << defPercent << "\n";
        std::cout << "Player Damage: " << this->character->getDamageMin() << " - " << this->character->getDamageMax() << "\n";
        std::cout << "Player HP: " << this->character->getHP() << "/" << this->character->getMaxHP() << "\n";
        std::cout << "Enemy Damage: " << enemy.getDamageMin() << " - " << enemy.getDamageMax() << "\n";
        std::cout << "Enemy HP: " << enemy.getHP() << "/" << enemy.getMaxHP() << "\n";
        std::cout << "----------------------------------------------------------------\n";

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

        turnDice = !turnDice;
        std::cin.get();
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
              << " (4) Rest Menu "
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
        this->character->resetStatus();
        std::cout << "You have rested...";
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