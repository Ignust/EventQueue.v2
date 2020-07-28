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
    mEventManager.subscribe(action,this);
}

//------------------------------------------------------------------------------------------
void IEventHandler::unsubscribeToEvent(EAction action)
//------------------------------------------------------------------------------------------
{
    //ThreadCout::get().print("IEventHandler::unsubscribeToEvent");
    mEventManager.unsubscribe(action,this);
}



