#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "BasicEventHandler.hpp"
#include <set>


class EventHandler: public BasicEventHandler {
public:
    EventHandler(std::string name);
    ~EventHandler();
    void handleEvent(std::shared_ptr<Event> event)override;

};

#endif //EVENTHANDLER_HPP
