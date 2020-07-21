#include "IEventHandler.hpp"
#include <iostream>

EventManager IEventHandler::mEventManager;

//------------------------------------------------------------------------------------------
IEventHandler::IEventHandler()
//------------------------------------------------------------------------------------------
{
    //subscribeToEvent(CREATION_OBJECT);
    //subscribeToEvent(DELETE_OBJECT);
    sendEvent(std::make_shared<Event>(Event(CREATION_OBJECT)));
}

//------------------------------------------------------------------------------------------
IEventHandler::~IEventHandler()
//------------------------------------------------------------------------------------------
{
    /*for (auto & action : mEventSubscriptionsSet) {
        std::cout << action << std::endl;
    }*/

    //unsubscribeToEvent(CREATION_OBJECT);
    //unsubscribeToEvent(DELETE_OBJECT);
    /*for(auto it = mEventSubscriptionsSet.begin(); it != mEventSubscriptionsSet.end();++it) {
        unsubscribeToEvent(*it);
        //mEventSubscriptionsSet.erase(it);
    }*/


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
    /*for(auto it = mEventSubscriptionsSet.begin(); it != mEventSubscriptionsSet.end();++it) {
        if (*it == action) {
            mEventSubscriptionsSet.erase(it);
            break;
        }
    }*/
    auto it = mEventSubscriptionsSet.find(action);
    if (it != mEventSubscriptionsSet.end()) {
        mEventSubscriptionsSet.erase(it);
        mEventManager.unsubscriptionToEvent(action,this);
    }


}



