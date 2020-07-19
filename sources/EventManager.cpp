#include "EventManager.hpp"

#include <thread>
#include <iostream>
//using namespace std;

//------------------------------------------------------------------------------------------
EventManager::EventManager()
//------------------------------------------------------------------------------------------
{
    std::thread th([&](){manageEvents();});
    th.detach();
}

//------------------------------------------------------------------------------------------
void EventManager::subscribe(IEventHandler* user)
//------------------------------------------------------------------------------------------
{
    std::lock_guard<std::mutex> lock(mMutex);
    mEventHandlerList.push_back(user);
}

//------------------------------------------------------------------------------------------
void EventManager::unsubscribe(IEventHandler* user)
//------------------------------------------------------------------------------------------
{
    for ( auto it = mEventHandlerList.begin(); it != mEventHandlerList.end(); ++it) {
        if (it.operator*() == user){
            mEventHandlerList.erase(it);
            break;
        }
    }
}

//------------------------------------------------------------------------------------------
void EventManager::pushEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    {
    std::lock_guard<std::mutex> lock(mMutex);
    mEventQueue.push(event);
    }
    //manageEvents();
}

//------------------------------------------------------------------------------------------
void EventManager::subscriptionToEvent(EAction event,IEventHandler* user)
//------------------------------------------------------------------------------------------
{
    mSubscriptionMap[event].push_back(user);
}

//------------------------------------------------------------------------------------------
void EventManager::manageEvents()
//------------------------------------------------------------------------------------------
{
    //cout << "start manageEvents" << endl;
    while (!mEventQueue.empty()) {
        //cout << "while start" << endl;
        mMutex.lock();
        std::shared_ptr<Event> tempEvent = mEventQueue.front();
        mEventQueue.pop();
        mMutex.unlock();
        sendEvent(tempEvent);
    }
    //cout << "while end" << endl;
    manageEvents();
}

//------------------------------------------------------------------------------------------
void EventManager::sendEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    for ( auto it = mEventHandlerList.begin(); it != mEventHandlerList.end(); ++it) {
        it.operator*()->handleEvent(event);
    }
}
