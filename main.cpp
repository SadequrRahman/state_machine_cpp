#include <iostream>
#include <StateMachine.hpp>
#include <PowerOnResetState.hpp>
#include <TestState.hpp>
#include <BaseEvent.hpp>
#include <thread>
#include <unistd.h>

using namespace std;

PowerOnResetState por;
TestState test;
StateMachine stateMachine(&por);

void loop()
{
    stateMachine.run();
}

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
    
    cout << "Application stated\r\n with hardware thread " << thread::hardware_concurrency() << endl;
    thread th1(loop);
    StateNode state0(&por);
    StateNode state1(&test);
    ExampleEvent e(1);
    ExampleEvent e1(2);
    state0.appendTransition(&test, 1);
    state1.appendTransition(&por,2);
    stateMachine.addState(state0);
    stateMachine.addState(state1);
    
    
    int counter = 0;
    while (1)
    {
        switch (counter)
        {
        case 10:
            stateMachine.queueEvent(&e);
            break;
        case 20:
            stateMachine.queueEvent(&e1);
            break;
        default:
            break;
        }
        sleep(1);
        counter++;
        if(counter > 30)
            counter = 0;
    }
    th1.join();


    return 0;
}



