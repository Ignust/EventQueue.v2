#include "IEventHandler.hpp"
#include <iostream>

EventManager IEventHandler::mEventManager;

//------------------------------------------------------------------------------------------
IEventHandler::IEventHandler()
//------------------------------------------------------------------------------------------
{
    subscribe();
    sendEvent(std::make_shared<Event>(Event(CREATION_OBJECT)));
}

//------------------------------------------------------------------------------------------
IEventHandler::~IEventHandler()
//------------------------------------------------------------------------------------------
{
    unsubscribe();
}

//------------------------------------------------------------------------------------------
void IEventHandler::sendEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    //std::cout << event->action << std::endl;
    mEventManager.pushEvent(event);
}

//------------------------------------------------------------------------------------------
void IEventHandler::subscribe()
//------------------------------------------------------------------------------------------
{    
    IEventHandler::mEventManager.subscribe(this);

}

//------------------------------------------------------------------------------------------
void IEventHandler::unsubscribe()
//------------------------------------------------------------------------------------------
{
    mEventManager.unsubscribe(this);
    sendEvent(std::make_shared<Event>(Event(DELETE_OBJECT)));    
}



