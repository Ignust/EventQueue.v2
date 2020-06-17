#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Event.hpp"
#include "IEventHandler.hpp"

#include <memory>
#include <thread>
#include <mutex>
#include <list>
#include <queue>

class IEventHandler;

class EventManager {
public:

    void subscribe(IEventHandler* user);
    void unsubscribe(IEventHandler* user);
    void pushEvent(std::shared_ptr<Event> event);
private:
    void manageEvents();

    std::list<IEventHandler*> mEventHandlerList;
    std::queue<std::shared_ptr<Event>> mEventQueue;
    std::mutex mMutex;
};

#endif //EVENTMANAGER_HPP
