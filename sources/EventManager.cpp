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
void EventManager::pushEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    std::lock_guard<std::mutex> lock(mMutex);
    mEventQueue.push(event);
}

//------------------------------------------------------------------------------------------
void EventManager::subscriptionToEvent(EAction action,IEventHandler* user)
//------------------------------------------------------------------------------------------
{
    std::lock_guard<std::mutex> lock(mMutex);

    mSubscriptionMap[action].push_back(user);
    if(!mRunning){
        mRunning = true;
        std::thread th([&](){manageEvents();});
        th.detach();
    }
}

//------------------------------------------------------------------------------------------
void EventManager::unsubscriptionToEvent(EAction action,IEventHandler* user)
//------------------------------------------------------------------------------------------
{
    std::lock_guard<std::mutex> lock(mMutex);

    auto pair = mSubscriptionMap.find(action);
    if (pair == mSubscriptionMap.end()){
        return;
    }

    auto & list = pair->second;
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (*it == user){
            it = list.erase(it);
            break;
        }
    }

    if(list.empty()){
        mSubscriptionMap.erase(action);
    }

    mRunning = !mSubscriptionMap.empty();
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
    std::lock_guard<std::mutex> lock(mMutex);
    auto pair = mSubscriptionMap.find(event->action);
    if (pair != mSubscriptionMap.end()) {
        const auto & list = pair->second;
        for (auto & subscriber : list) {
             subscriber->handleEvent(event);
        }
    }

}

//------------------------------------------------------------------------------------------
bool EventManager::getRunning()
//------------------------------------------------------------------------------------------
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mRunning;
}


