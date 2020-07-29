#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Event.hpp"
#include "BasicEventHandler.hpp"

#include <memory>
#include <mutex>
#include <list>
#include <queue>
#include <map>

class BasicEventHandler;

class EventManager {
public:

    EventManager();
    ~EventManager();
    void pushEvent(std::shared_ptr<Event> event);
    void subscribe(EAction event, BasicEventHandler* handler);
    void unsubscribe(EAction event, BasicEventHandler* handler);
private:
    void manageEvents();
    void sendEvent(std::shared_ptr<Event> event);

    std::queue<std::shared_ptr<Event>> mEventQueue;
    std::map<EAction,std::list<BasicEventHandler*>> mSubscribersMap;
    std::mutex mMutexEvents;
    std::mutex mMutexSubscribers;
    bool mHandlerThreadRunning;
};

#endif //EVENTMANAGER_HPP
