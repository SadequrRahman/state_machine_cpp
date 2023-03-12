#pragma once

#include <AbstractState.hpp>

class PowerOnResetState : public AbstractState
{
private:
    /* data */
public:
    PowerOnResetState(/* args */);
    ~PowerOnResetState();

    void onEntry(void);
    void onExecute(void);
    void onExit(void);


};

