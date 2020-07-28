#include "IEventHandler.hpp"
#include "ThreadCout.hpp"
#include <iostream>

EventManager IEventHandler::mEventManager;

//------------------------------------------------------------------------------------------
IEventHandler::IEventHandler(std::string name)
    : mName(name)
//------------------------------------------------------------------------------------------
{
    std::ostringstream os;
            os << getName() << ": " << "IEventHandler()" << std::endl;
            ThreadCout::get().print(os);
    //subscribeToEvent(CREATION_OBJECT);
    //subscribeToEvent(DELETE_OBJECT);
    sendEvent(std::make_shared<Event>(Event(CREATION_OBJECT)));
}

//------------------------------------------------------------------------------------------
IEventHandler::~IEventHandler()
//------------------------------------------------------------------------------------------
{
    std::ostringstream os;
    os << getName() << ": " << "~IEventHandler()" << std::endl;
    ThreadCout::get().print(os);

    while (!mEventSubscriptionsSet.empty()) {
            unsubscribeToEvent(*mEventSubscriptionsSet.begin());
        }


    sendEvent(std::make_shared<Event>(Event(DELETE_OBJECT)));
}

//------------------------------------------------------------------------------------------
void IEventHandler::sendEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    mEventManager.pushEvent(event);
}

//------------------------------------------------------------------------------------------
void IEventHandler::subscribeToEvent(EAction action)
//------------------------------------------------------------------------------------------
{
    mEventSubscriptionsSet.insert(action);
    mEventManager.subscriptionToEvent(action,this);
}

//------------------------------------------------------------------------------------------
void IEventHandler::unsubscribeToEvent(EAction action)
//------------------------------------------------------------------------------------------
{
    mEventSubscriptionsSet.erase(action);
    mEventManager.unsubscriptionToEvent(action,this);
}



