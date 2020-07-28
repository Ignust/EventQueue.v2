#ifndef IEVENTHANDLER_HPP
#define IEVENTHANDLER_HPP

#include "EventManager.hpp"
#include <memory>
#include <set>
#include <string>
//#include <iostream>

class EventManager;


class IEventHandler {
public:
    IEventHandler(std::string name, std::shared_ptr<IEventHandler> obj);
    virtual~IEventHandler();
    virtual void handleEvent(std::shared_ptr<Event> event) = 0;
    void subscribeToEvent(EAction action);
    void unsubscribeToEvent(EAction action);
    inline std::string getName(){return mName;}
    void initPtr(std::shared_ptr<IEventHandler> obj){mThis = obj; /*std::cout << "obj = " << obj.use_count() << std::endl;*/}

protected:
    void sendEvent(std::shared_ptr<Event> event);
private:
    static EventManager mEventManager;
    std::set<EAction> mEventSubscriptionsSet;
    std:: string mName;
    std::weak_ptr<IEventHandler> mThis;
};

#endif //IEVENTHANDLER_HPP
