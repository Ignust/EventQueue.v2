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
    ~EventManager();
    void pushEvent(std::shared_ptr<Event> event);
    void subscribe(EAction event, IEventHandler* handler);
    void unsubscribe(EAction event, IEventHandler* handler);
private:
    void manageEvents();
    void sendEvent(std::shared_ptr<Event> event);

    std::queue<std::shared_ptr<Event>> mEventQueue;
    std::map<EAction,std::list<IEventHandler*>> mSubscribersMap;
    std::mutex mMutexEvents;
    std::mutex mMutexSubscribers;
    bool mHandlerThreadRunning;
};

#endif //EVENTMANAGER_HPP
