#pragma once

class AbstractState
{
public:
    virtual void onEntry(void) = 0;
    virtual void onExit(void) = 0;
    virtual void onExecute(void) = 0;
};


