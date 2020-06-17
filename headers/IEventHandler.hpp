#ifndef IEVENTHANDLER_HPP
#define IEVENTHANDLER_HPP

#include "EventManager.hpp"

#include <memory>

class EventManager;


class IEventHandler {
public:
    virtual void handleEvent(std::shared_ptr<Event> event) = 0;
    virtual void sendEvent(std::shared_ptr<Event> event) = 0;
private:
    void subscribe();
    void unsubscribe();
    EventManager* mEventManager;
};

#endif //IEVENTHANDLER_HPP
