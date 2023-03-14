#include <EventManager.hpp>

template<typename EventType>
EventManager<EventType>::EventManager()
{
    
}

template<typename EventType>
EventManager<EventType>::~EventManager()
{

}

template<typename EventType>
void EventManager<EventType>::registerEvent(EventType event)
{
    eventQueue.push(event);
}

template<typename EventType>
EventType EventManager<EventType>::dispatchEvent(void)
{
    EventType event = eventQueue.front();
    eventQueue.pop();
    return event;
}

template<typename EventType>
uint32_t EventManager<EventType>::isEventAvailable()
{
    return eventQueue.size();
}
