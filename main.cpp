#include <iostream>
#include "EventHandler.hpp"
#include "thread"
#include "chrono"


int main()
{
    std::cout << "start main" << std::endl;

    EventHandler* obj2 = new EventHandler();
    EventHandler obj1;
    delete obj2;

    //std::shared_ptr<Event> event(new Event);
    //event->action = ACTION1;
    //obj1.sendEvent(event);


    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "end main" << std::endl;

    return 0;
}
