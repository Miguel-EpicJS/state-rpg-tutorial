#include "../includes/State.h"

State::State(/* args */)
{
    this->quit = false;
}

State::~State()
{
}

const bool& State::getQuit() const
{
    return this->quit;
}

int State::getChoice() const
{
    int choice = 0;

    std::cout << " Choice: ";
    std::cin >> std::setw(1)  >> choice;
    std::cin.clear();
    std::cin.sync();

    while (!std::cin.good())
    {
        std::cout << " ERROR: Faulty Input!\n";

        std::cin.clear();
        std::cin.sync();

        std::cout << " - Enter choice: ";
        std::cin >> std::setw(1) >> choice;
    }

    return choice;
}

void State::setQuit(const bool quit)
{
    this->quit = quit;
}
