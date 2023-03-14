#pragma once

#include <vector>
#include <queue>
#include <StateNode.hpp>
#include <EventManager.hpp>
#include <BaseEvent.hpp>


class StateMachine 
{

public:

    StateMachine(AbstractState* state);
    ~StateMachine();
    void addState(StateNode state);
    void queueEvent(BaseEvent* event);
    uint32_t isEventAvailable(void);
    void run(void);
    void operator()(void);

private:
    /* data */
    std::vector<StateNode> table;
    std::queue<BaseEvent*> eQueue;
    AbstractState* cState;
    AbstractState* nState;

};

