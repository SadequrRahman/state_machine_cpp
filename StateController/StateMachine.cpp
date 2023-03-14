#include <StateMachine.hpp>
#include <iostream>
#include <unistd.h>
#include <csignal>



static bool isRunning = true;


void signalHandler(int signum)
{
    std::cout << "Interrupt signal (" << signum << ") received.\n" << std::endl;
    isRunning = false;

    usleep(5000);
    exit(signum);  
}

StateMachine::StateMachine():
cState(nullptr),nState(nullptr)
{
    signal(SIGINT, signalHandler);
    std::cout << "creating State machine" << std::endl;
}

StateMachine::StateMachine(AbstractState *state):
cState(state),nState(nullptr)
{
    signal(SIGINT, signalHandler);
    std::cout << "creating State machine with por state" << std::endl;
}

StateMachine::~StateMachine()
{
    std::cout << "destroying State machine" << std::endl;
}

void StateMachine::addState(StateNode state)
{
    table.push_back(state);
}

void StateMachine::queueEvent(BaseEvent* event)
{
    eQueue.push(event);
}


uint32_t StateMachine::isEventAvailable(void)
{
    return eQueue.size();
}

void StateMachine::run(void)
{
    int indx(0);
    cState->onEntry();

    while (isRunning)
    {
        cState->onExecute();
        if(isEventAvailable())
        {
            BaseEvent* e = eQueue.front();
            nState = table.at(indx).getNextState(e->getEventIdentifier());
            if(nState != cState)
            {
            for (size_t i = 0; table.size(); i++)
            {
                if(table.at(i).getState() == nState)
                {
                    indx = i;
                    cState = nState;
                    break;
                }
            }
            }
            eQueue.pop();
        }
        
        

        sleep(1);
    }
    
}
