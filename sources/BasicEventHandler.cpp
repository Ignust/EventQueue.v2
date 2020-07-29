#include "BasicEventHandler.hpp"
#include "ThreadCout.hpp"
#include <iostream>

EventManager BasicEventHandler::mEventManager;

//------------------------------------------------------------------------------------------
BasicEventHandler::BasicEventHandler(std::string name)
    : mName(name)
//------------------------------------------------------------------------------------------
{
    std::ostringstream os;
    os << getName() << ": " << "BasicEventHandler()" << std::endl;
    ThreadCout::get().print(os);
}

//------------------------------------------------------------------------------------------
BasicEventHandler::~BasicEventHandler()
//------------------------------------------------------------------------------------------
{
    std::ostringstream os;
    os << getName() << ": " << "~BasicEventHandler()" << std::endl;
    ThreadCout::get().print(os);

    while (!mEventSubscriptionsSet.empty()) {
            unsubscribeFromEvent(*mEventSubscriptionsSet.begin());
        }
}

//------------------------------------------------------------------------------------------
void BasicEventHandler::handleEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    event.get();//**//
    std::ostringstream os;
    os << getName() << ": " << "BasicEventHandler::handleEvent()" << std::endl;
    ThreadCout::get().print(os);
}

//------------------------------------------------------------------------------------------
void BasicEventHandler::subscribeToEvent(EAction action)
//------------------------------------------------------------------------------------------
{
    mEventSubscriptionsSet.insert(action);
    mEventManager.subscribe(action,this);
}

//------------------------------------------------------------------------------------------
void BasicEventHandler::unsubscribeFromEvent(EAction action)
//------------------------------------------------------------------------------------------
{
    //ThreadCout::get().print("BasicEventHandler::unsubscribeToEvent");
    mEventSubscriptionsSet.erase(action);
    mEventManager.unsubscribe(action,this);
}

//------------------------------------------------------------------------------------------
void BasicEventHandler::sendEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    mEventManager.pushEvent(event);
}





