#pragma once

#include <BaseEvent.hpp>
#include <queue>


template<typename EventType>
class EventManager
{
 
public:
    EventManager();
    virtual ~EventManager();

    void registerEvent(EventType event);
    EventType dispatchEvent(void);
    uint32_t isEventAvailable();

private:
    
    std::queue<EventType> eventQueue;

};

