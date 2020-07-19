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



    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    //IEventHandler::mEventManager.pushEvent(std::make_shared<Event>(STOP_MANAGER_EVENTS));
    std::cout << "end main" << std::endl;

    return 0;
}
