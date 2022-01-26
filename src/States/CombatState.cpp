#include "../../includes/CombatState.h"

CombatState::CombatState(Character*& character, std::stack<State *>* states) : State(), character(character)
{
    this->states = states;
}

CombatState::~CombatState()
{
}

void CombatState::beginCombat()
{
    Enemy enemy(this->character->getLevel());
    bool end_combat = false;

    int turnDice  = rand() % 2;
    int round = 0;

    srand(time(NULL));

    std::cin.get();
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
            this->setQuit(true);
        }
        else if (enemy.getIsDead())
        {
            end_combat = true;
            int gainExp = rand()%(enemy.getLevel() * 10) + 1;
            std::cout << "YOU DEAFEATED THE ENEMY AND GAINED " << gainExp << " EXP!\n";
            this->character->addExp(gainExp);
            this->setQuit(true);
        }

        turnDice = !turnDice;
        std::cin.get();
    }
}

void CombatState::printMenu()
{
    std::cout << " --- Combat Menu --- \n\n"
        << this->character->getMenuBar() << "\n\n"
        << " (1) Begin Combat\n"
        << " (2) Flee\n"
        << " (3) Heal\n\n";
}

void CombatState::updateMenu()
{
    switch (this->getChoice())
    {
    case 1:
        this->beginCombat();
        std::cout << "END OF COMBAT.\n";
        break;
    case 2:
        std::cout << "You fled and lost some valuables...\n";
        std::cout << this->character->flee() << "\n";
        this->setQuit(true);
        break;
    case 3:
        this->character->resetStatus();
        std::cout << "(TESTING) You have rested... \n" ;
        break;
    case 4:
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
