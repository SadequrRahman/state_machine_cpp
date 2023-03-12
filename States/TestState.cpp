#include <TestState.hpp>
#include <iostream>

using namespace std;

TestState::TestState(/* args */)
{
}

TestState::~TestState()
{
}

void TestState::onEntry()
{
    cout << "TestState onEntry" << endl;
}

void TestState::onExecute()
{
    cout << "TestState onExecute" << endl;
}

void TestState::onExit()
{
    cout << "TestState onExit" << endl;
}
