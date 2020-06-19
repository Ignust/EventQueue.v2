#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "IEventHandler.hpp"


class EventHandler: public IEventHandler {
public:
    EventHandler();
    ~EventHandler();
    void handleEvent(std::shared_ptr<Event> event)override;
    void sendEvent(std::shared_ptr<Event> event)override;
};

#endif //EVENTHANDLER_HPP
