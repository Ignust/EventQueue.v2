#include <iostream>
#include "EventHandler.hpp"


int main()
{
    std::cout << "start main" << std::endl;

    EventHandler obj1;
    std::shared_ptr<Event> event(new Event);
    event->action = ACTION1;
    obj1.sendEvent(event);
    std::cout << "end main" << std::endl;

    return 0;
}
