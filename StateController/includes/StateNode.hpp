#pragma once

#include <AbstractState.hpp>
#include <map>
#include <vector>


class StateNode
{

public:
    StateNode(AbstractState* state);
    ~StateNode();
    AbstractState* getNextState(int event);
    void appendTransition(AbstractState* state, int event);
    AbstractState* getState(void);

private:
    AbstractState* state;
    std::map<int, AbstractState*> graph;

};
