#pragma once

#include <iostream>
#include <iomanip>

class State
{
private:
    /* data */
    bool quit;
public:
    State(/* args */);
    virtual ~State();

    const bool& getQuit() const;
    void setQuit(const bool quit);

    virtual int getChoice() const;
    virtual void update() = 0;
};