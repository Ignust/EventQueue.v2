#include "IEventHandler.hpp"
#include "ThreadCout.hpp"
#include <thread>
#include <iostream>
EventManager IEventHandler::mEventManager;

//------------------------------------------------------------------------------------------
IEventHandler::IEventHandler(std::string name, std::shared_ptr<IEventHandler> obj)
    : mName(name)
    , mThis(obj)
//------------------------------------------------------------------------------------------
{
        ostringstream os;
        os << getName() << ": " << "IEventHandler()" << endl;
        ThreadCout::get().print(os);
        //subscribeToEvent(CREATION_OBJECT);
        //subscribeToEvent(DELETE_OBJECT);
        sendEvent(std::make_shared<Event>(Event(CREATION_OBJECT)));
}

//------------------------------------------------------------------------------------------
IEventHandler::~IEventHandler()
//------------------------------------------------------------------------------------------
{

    ostringstream os;
    os << getName() << ": " << "~IEventHandler()" << endl;
    ThreadCout::get().print(os);

    //unsubscribeToEvent(CREATION_OBJECT);
    //unsubscribeToEvent(DELETE_OBJECT);

    /*auto set = mEventSubscriptionsSet;

    for (auto & action : set) {
        unsubscribeToEvent(action);
    }*/


    /*for(auto it = mEventSubscriptionsSet.begin(); it != mEventSubscriptionsSet.end();++it) {
       unsubscribeToEvent(*it);
        //mEventSubscriptionsSet.erase(it);
    }*/

    while (!mEventSubscriptionsSet.empty()) {
        unsubscribeToEvent(*mEventSubscriptionsSet.begin());
    }
    //ThreadCout::get().print("sendEvent");
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
    ostringstream os;
    os << getName() << ": " << "IEventHandler::subscribeToEvent()" << endl;
    ThreadCout::get().print(os);
    mEventSubscriptionsSet.insert(action);
    mEventManager.subscriptionToEvent(action,mThis);
}

//------------------------------------------------------------------------------------------
void IEventHandler::unsubscribeToEvent(EAction action)
//------------------------------------------------------------------------------------------
{
    /*auto it = mEventSubscriptionsSet.find(action);
    if (it != mEventSubscriptionsSet.end()) {
        //std::cout << "it = " << *it << std::endl;
        //it = mEventSubscriptionsSet.erase(it);
    }*/
    //auto deleteEvent = mEventSubscriptionsSet.erase(action);
    mEventSubscriptionsSet.erase(action);
    mEventManager.unsubscriptionToEvent(action,mThis);


}



