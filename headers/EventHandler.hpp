#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "IEventHandler.hpp"
#include <set>


class EventHandler: public IEventHandler {
public:
    EventHandler(std::string name);
    ~EventHandler();
    void handleEvent(std::shared_ptr<Event> event)override;

};

#endif //EVENTHANDLER_HPP
