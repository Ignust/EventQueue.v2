#ifndef IEVENTHANDLER_HPP
#define IEVENTHANDLER_HPP

#include "EventManager.hpp"

#include <memory>
#include <set>

class EventManager;


class IEventHandler {
public:
    IEventHandler();
    virtual~IEventHandler();
    virtual void handleEvent(std::shared_ptr<Event> event) = 0;
    void subscribeToEvent(EAction action);
    void unsubscribeToEvent(EAction action);

protected:
    void sendEvent(std::shared_ptr<Event> event);
private:
    static EventManager mEventManager;
    std::set<EAction> mEventSubscriptionsSet;
};

#endif //IEVENTHANDLER_HPP
