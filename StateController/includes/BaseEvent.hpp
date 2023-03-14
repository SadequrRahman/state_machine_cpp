#pragma once

#include <stdint.h>


template<typename EventParams>
class BaseEvent
{

public:
    virtual EventParams getEventParams(void) = 0;
    virtual EventParams getEventIdentifier(void) = 0;
};
