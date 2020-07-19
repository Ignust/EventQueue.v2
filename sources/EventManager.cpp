#include "EventManager.hpp"

#include <thread>
//#include <iostream>
//using namespace std;

//------------------------------------------------------------------------------------------
EventManager::EventManager()
    : mRunning(false)
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
void EventManager::subscribe(IEventHandler* user)
//------------------------------------------------------------------------------------------
{
    std::lock_guard<std::mutex> lock(mMutex);

    mEventHandlerList.push_back(user);
    if(!mRunning){
        mRunning = true;
        std::thread th([&](){manageEvents();});
        th.detach();
    }
}

//------------------------------------------------------------------------------------------
void EventManager::unsubscribe(IEventHandler* user)
//------------------------------------------------------------------------------------------
{
    std::lock_guard<std::mutex> lock(mMutex);

    for ( auto it = mEventHandlerList.begin(); it != mEventHandlerList.end(); ++it) {
        if (it.operator*() == user){
            mEventHandlerList.erase(it);
            break;
        }
    }
    mRunning = !mEventHandlerList.empty();
}

//------------------------------------------------------------------------------------------
void EventManager::pushEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    std::lock_guard<std::mutex> lock(mMutex);
    mEventQueue.push(event);
}

//------------------------------------------------------------------------------------------
void EventManager::manageEvents()
//------------------------------------------------------------------------------------------
{
    while (getRunning()) {
        while (!mEventQueue.empty()) {
            mMutex.lock();
            std::shared_ptr<Event> tempEvent = mEventQueue.front();
            mEventQueue.pop();
            mMutex.unlock();
            sendEvent(tempEvent);
        }
    }
    //cout << "manageEvents end" << endl;
}

//------------------------------------------------------------------------------------------
void EventManager::sendEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    for ( auto it = mEventHandlerList.begin(); it != mEventHandlerList.end(); ++it) {
        it.operator*()->handleEvent(event);
    }
}

//------------------------------------------------------------------------------------------
bool EventManager::getRunning()
//------------------------------------------------------------------------------------------
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mRunning;
}


