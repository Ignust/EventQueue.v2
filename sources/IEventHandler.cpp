#include "IEventHandler.hpp"

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
    sendEvent(std::make_shared<Event>(Event(DELETE_OBJECT)));
}

//------------------------------------------------------------------------------------------
void IEventHandler::sendEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    mEventManager.pushEvent(event);
}

//------------------------------------------------------------------------------------------
void IEventHandler::subscribe()
//------------------------------------------------------------------------------------------
{
    mEventManager.subscriptionToEvent(CREATION_OBJECT,this);
    mEventManager.subscriptionToEvent(DELETE_OBJECT,this);
}

//------------------------------------------------------------------------------------------
void IEventHandler::unsubscribe()
//------------------------------------------------------------------------------------------
{
    mEventManager.unsubscriptionToEvent(CREATION_OBJECT,this);
    mEventManager.unsubscriptionToEvent(DELETE_OBJECT,this);
}



