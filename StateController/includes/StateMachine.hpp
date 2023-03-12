#pragma once

#include <vector>
#include <StateNode.hpp>

class StateMachine
{

public:
    StateMachine();
    StateMachine(AbstractState* state);
    ~StateMachine();
    void addState(StateNode state);
    void run(void);

private:
    /* data */
    std::vector<StateNode> table;
    AbstractState* cState;
    AbstractState* nState;

};

