#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Event.hpp"
#include "IEventHandler.hpp"
#include"ThreadCout.hpp"

#include <memory>
#include <mutex>
#include <list>
#include <queue>
#include <map>

class IEventHandler;

class EventManager {
public:

    EventManager();
    ~EventManager();
    void pushEvent(std::shared_ptr<Event> event);
    void subscriptionToEvent(EAction action,std::weak_ptr<IEventHandler> user);
    void unsubscriptionToEvent(EAction action,std::weak_ptr<IEventHandler> user);
private:
    void manageEvents();
    void sendEvent(std::shared_ptr<Event> event);
    bool getRunning();

    std::queue<std::shared_ptr<Event>> mEventQueue;
    std::map<EAction,std::list<std::weak_ptr<IEventHandler>>> mSubscriptionMap;
    std::mutex mMutex;
    bool mRunning;
};

#endif //EVENTMANAGER_HPP
