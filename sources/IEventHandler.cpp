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
}

//------------------------------------------------------------------------------------------
IEventHandler::~IEventHandler()
//------------------------------------------------------------------------------------------
{
    std::ostringstream os;
    os << getName() << ": " << "~IEventHandler()" << std::endl;
    ThreadCout::get().print(os);

    while (!mEventSubscriptionsSet.empty()) {
            unsubscribeFromEvent(*mEventSubscriptionsSet.begin());
        }
}

//------------------------------------------------------------------------------------------
void IEventHandler::handleEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    event.get();//**//
    std::ostringstream os;
    os << getName() << ": " << "IEventHandler::handleEvent()" << std::endl;
    ThreadCout::get().print(os);
}

//------------------------------------------------------------------------------------------
void IEventHandler::subscribeToEvent(EAction action)
//------------------------------------------------------------------------------------------
{
    mEventSubscriptionsSet.insert(action);
    mEventManager.subscribe(action,this);
}

//------------------------------------------------------------------------------------------
void IEventHandler::unsubscribeFromEvent(EAction action)
//------------------------------------------------------------------------------------------
{
    //ThreadCout::get().print("IEventHandler::unsubscribeToEvent");
    mEventSubscriptionsSet.erase(action);
    mEventManager.unsubscribe(action,this);
}

//------------------------------------------------------------------------------------------
void IEventHandler::sendEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    mEventManager.pushEvent(event);
}





