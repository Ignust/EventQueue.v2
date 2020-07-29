#include "EventManager.hpp"
#include "ThreadCout.hpp"

#include <thread>
//#include <iostream>
//using namespace std;

//------------------------------------------------------------------------------------------
EventManager::EventManager()
    : mHandlerThreadRunning(false)
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
EventManager::~EventManager()
//------------------------------------------------------------------------------------------
{
    ThreadCout::get().print("EventManager::~EventManager()");
}

//------------------------------------------------------------------------------------------
void EventManager::pushEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    std::lock_guard<std::mutex> lock(mMutexSubscribers);
    if (mHandlerThreadRunning){
        mEventQueue.push(event);
    }
}

//------------------------------------------------------------------------------------------
void EventManager::subscribe(EAction event, BasicEventHandler* handler)
//------------------------------------------------------------------------------------------
{
    //ThreadCout::get().print("EventManager::subscribe-------------");
    std::lock_guard<std::mutex> lock(mMutexSubscribers);

    mSubscribersMap[event].push_back(handler);
    if(!mHandlerThreadRunning){
        mHandlerThreadRunning = true;
        std::thread th([&](){manageEvents();});
        th.detach();
    }
}

//------------------------------------------------------------------------------------------
void EventManager::unsubscribe(EAction event,BasicEventHandler* handler)
//------------------------------------------------------------------------------------------
{
    std::lock_guard<std::mutex> lock(mMutexSubscribers);

    auto pair = mSubscribersMap.find(event);
    if (pair == mSubscribersMap.end()){
        return;
    }

    auto & list = pair->second;
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (*it == handler){
            //ThreadCout::get().print("EventManager::unsubscriptionToEvent()---");
            it = list.erase(it);
            break;
        }
    }

    if(list.empty()){
        mSubscribersMap.erase(event);
    }
    mHandlerThreadRunning = !mSubscribersMap.empty();
}

//------------------------------------------------------------------------------------------
void EventManager::manageEvents()
//------------------------------------------------------------------------------------------
{
    //ThreadCout::get().print("EventManager::manageEvents() start");
    while (mHandlerThreadRunning) {
        while (!mEventQueue.empty()) {
            mMutexEvents.lock();
            std::shared_ptr<Event> tempEvent = mEventQueue.front();
            mEventQueue.pop();
            mMutexEvents.unlock();
            sendEvent(tempEvent);
        }
    }
    //ThreadCout::get().print("EventManager::manageEvents() end");
}

//------------------------------------------------------------------------------------------
void EventManager::sendEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    std::lock_guard<std::mutex> lock(mMutexSubscribers);
    auto pair = mSubscribersMap.find(event->action);
    if (pair != mSubscribersMap.end()) {
        const auto & list = pair->second;
        for (auto & subscriber : list) {
            std::ostringstream os;
            os << "EventManager::sendEvent to "<<subscriber->getName() << std::endl;
            ThreadCout::get().print(os);
             subscriber->handleEvent(event);
        }
    }

}



