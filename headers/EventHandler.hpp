#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

//#include <set>

#include "IEventHandler.hpp"




class EventHandler: public IEventHandler {
public:
    EventHandler(std::string name, std::shared_ptr<IEventHandler> obj);
    ~EventHandler();
    void handleEvent(std::shared_ptr<Event> event)override;


};

#endif //EVENTHANDLER_HPP
