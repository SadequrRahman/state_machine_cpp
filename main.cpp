#include <iostream>
#include <StateMachine.hpp>
#include <PowerOnResetState.hpp>
#include <TestState.hpp>
#include <BaseEvent.hpp>

using namespace std;

PowerOnResetState por;
TestState test;
StateMachine stateMachine(&por);

class ExampleEvent : public BaseEvent
{
public:
    ExampleEvent(uint64_t id):
    id(id)
    {

    }

    virtual ~ExampleEvent()
    {

    }

    uint64_t getEventIdentifier()
    {
        return id;
    }

    void* getEventParams()
    {
        return nullptr;
    }


private:
    uint64_t id;
};

int main (int argc, char **argv)
{
    
    cout << "Application stated" << endl;

    StateNode state0(&por);
    StateNode state1(&test);
    ExampleEvent e(1);


    state0.appendTransition(&test, 1);
    stateMachine.addState(state0);
    stateMachine.addState(state1);
    stateMachine.queueEvent(&e);

    stateMachine.run();

    return 0;
}



