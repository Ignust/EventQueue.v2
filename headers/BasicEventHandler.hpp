#ifndef BASICEVENTHANDLER_HPP
#define BASICEVENTHANDLER_HPP

#include "EventManager.hpp"

#include <memory>
#include <set>

class EventManager;


class BasicEventHandler {
public:
    BasicEventHandler(std::string name);
    virtual~BasicEventHandler();
    virtual void handleEvent(std::shared_ptr<Event> event);
    void subscribeToEvent(EAction action);
    void unsubscribeFromEvent(EAction action);
    inline std::string getName(){return mName;}

protected:
    void sendEvent(std::shared_ptr<Event> event);
private:
    static EventManager mEventManager;
    std::set<EAction> mEventSubscriptionsSet;
    std::string mName;
};

#endif //BASICEVENTHANDLER_HPP
