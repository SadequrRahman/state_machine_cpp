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

void StateMachine::run(void)
{
    int e = 0;
    int indx = 0;
    int counter = 0;
    bool isDone = false;
    cState->onEntry();
    while (isRunning)
    {
        nState = table.at(indx).getNextState(e);
        if(nState != cState)
        {
            for (size_t i = 0; table.size(); i++)
            {
                if(table.at(i).getState() == nState)
                {
                    indx = i;
                    cState = nState;
                    isDone = true;
                    e  = 0;
                    counter = 0;
                    break;
                }
            }
        }

        if(!isDone)
            counter++;

        if(counter == 10)
        {
            e = 1;
        }
        sleep(1);
    }
    
}
