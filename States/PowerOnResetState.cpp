#include <PowerOnResetState.hpp>
#include <iostream>

using namespace std;


PowerOnResetState::PowerOnResetState()
{
}

PowerOnResetState::~PowerOnResetState()
{
}

void PowerOnResetState::onEntry(void)
{
    cout << "Power on reset onEntry" << endl;
}


void PowerOnResetState::onExecute(void)
{
    cout << "Power on reset onExecute" << endl;
}

void PowerOnResetState::onExit(void)
{
    cout << "Power on reset onExit" << endl;
}
