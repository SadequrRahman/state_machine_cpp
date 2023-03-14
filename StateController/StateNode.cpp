#include <StateNode.hpp>
#include <algorithm>


StateNode::StateNode(AbstractState* state):
state(state)
{
}

StateNode::~StateNode()
{
}

AbstractState* StateNode::getNextState(int event)
{
    // TO DO need to check vaild event for
    if(graph.find(event)->second)
    {
        state->onExit();
        graph[event]->onEntry();
        return graph[event];
    }
    return nullptr;
}

void StateNode::appendTransition(AbstractState* state, int event)
{
    graph[event] = state;
}

AbstractState *StateNode::getState(void)
{
    return state;
}
