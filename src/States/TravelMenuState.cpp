#include "../../includes/TravelMenuState.h"

TravelMenuState::TravelMenuState(Character *&character, std::stack<State *> *states) : character(character), State()
{
    this->states = states;
    this->locationString = "NONE";
    this->updateEncounterMenu();
    this->nrOfLocations = 5;
}

TravelMenuState::~TravelMenuState()
{
}

void TravelMenuState::travel()
{
}

void TravelMenuState::printMenu()
{
    std::cout << " --- Travel Menu --- \n\n"
              << this->character->getMenuBar() << "\n\n"
              << this->character->toStringPosition() << "\n\n"
              << "Location: " << this->locationString << "\n\n"
              << "Minimap: \n"
              << this->minimapString << "\n\n"
              << " (-1) Back to Menu\n"
              << " (1) UP\n"
              << " (2) DOWN\n"
              << " (3) LEFT\n"
              << " (4) RIGHT\n";
}

void TravelMenuState::updateEncounterMenu()
{
    if (!this->getQuit())
    {
        /* code */

        srand(this->character->getSeed());
        int location = rand() % 5 /* nrOf locations */;

        switch (location)
        {
        case EMPTY:
        {
            this->locationString = "You are in an empty plane.";

            int randomr = rand() % 2;

            if (randomr)
            {
                std::cout << "ENEMY ENCOUNTERED!\n";
                this->states->push(new CombatState(this->character, this->states));
            }
            break;
        }
        case FARM:
            this->locationString = "You are in a farm.";
            break;
        case CITY:
            this->locationString = "You are in a city.";
            break;
        case SHOP:
            this->locationString = "You find a shop.";
            break;
        case CHEST:
            this->locationString = "You found a chest.";
            break;
        default:
            this->locationString = "ERROR NO SUCH LOCATION!";
            break;
        }
    }
}
void TravelMenuState::updateMinimap()

{
    std::stringstream ss;

    int startX = this->character->getX() - 2;
    if (startX < 0)
    {
        startX = 0;
    }

    int startY = this->character->getY() - 2;

    if (startY < 0)
    {
        startY = 0;
    }

    int endX = this->character->getX() + 2;
    int endY = this->character->getY() + 2;

    for (size_t y = startY; y <= endY; y++)
    {
        for (size_t x = startX; x <= endX; x++)
        {
            srand(x + y);
            int location = rand() % 5 /* nrOf locations */;

            if (x == this->character->getX() && y == this->character->getY())
            {
                ss << "(P) ";
            }
            else
            {
                switch (location)
                {
                case EMPTY:
                    ss << "Emp ";
                    break;
                case FARM:
                    ss << "Far ";
                    break;
                case CITY:
                    ss << "Cit ";
                    break;
                case SHOP:
                    ss << "Sho ";
                    break;
                case CHEST:
                    ss << "Che ";
                    break;
                default:
                    ss << "XXX ";
                    break;
                }
            }
        }

        ss << "\n";
    }
    this->minimapString = ss.str();
}

void TravelMenuState::updateMenu()
{
    switch (this->getChoice())
    {
    case -1:
        this->setQuit(true);
        break;
    case 1:
        this->character->move(0, -1);
        break;
    case 2:
        this->character->move(0, 1);
        break;
    case 3:
        this->character->move(-1, 0);
        break;
    case 4:
        this->character->move(1, 0);
        break;
    default:
        std::cout << "Not a valid option! \n\n";
        break;
    }
}

void TravelMenuState::update()
{
    this->updateMinimap();
    this->printMenu();
    this->updateMenu();
    this->updateEncounterMenu();
}
