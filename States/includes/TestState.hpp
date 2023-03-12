#pragma once

#include <AbstractState.hpp>


class TestState : public AbstractState
{
private:
    /* data */
public:
    TestState(/* args */);
    ~TestState();

    void onEntry();
    void onExecute();
    void onExit();
};

