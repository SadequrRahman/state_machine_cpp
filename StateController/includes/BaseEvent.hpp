#pragma once

#include <stdint.h>



class BaseEvent
{

public:
    
    virtual uint64_t getEventIdentifier(void) = 0;
    virtual void *getEventParams(void) = 0;
};
 