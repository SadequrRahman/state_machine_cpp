#include <iostream>
#include <StateMachine.hpp>
#include <PowerOnResetState.hpp>
#include <TestState.hpp>

using namespace std;

PowerOnResetState por;
TestState test;
StateMachine stateMachine(&por);

int main (int argc, char **argv)
{

    cout << "Application stated" << endl;

    StateNode state0(&por);
    StateNode state1(&test);

    state0.appendTransition(&test, 1);
    stateMachine.addState(state0);
    stateMachine.addState(state1);

    stateMachine.run();

    return 0;
}