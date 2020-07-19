#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Event.hpp"
#include "IEventHandler.hpp"

#include <memory>
#include <mutex>
#include <list>
#include <queue>
#include <map>

class IEventHandler;

class EventManager {
public:

    EventManager();
    void subscribe(IEventHandler* user);
    void unsubscribe(IEventHandler* user);
    void pushEvent(std::shared_ptr<Event> event);
    void subscriptionToEvent(EAction event,IEventHandler* user);
private:
    void manageEvents();
    void sendEvent(std::shared_ptr<Event> event);
    bool getRunning();

    std::list<IEventHandler*> mEventHandlerList;
    std::queue<std::shared_ptr<Event>> mEventQueue;
    std::map<EAction,std::list<IEventHandler*>> mSubscriptionMap;
    std::mutex mMutex;
    bool mRunning;
};

#endif //EVENTMANAGER_HPP
