#include <iostream>
#include "EventHandler.hpp"
#include "thread"
#include "chrono"


int main()
{
    std::cout << "start main" << std::endl;

    EventHandler* obj2 = new EventHandler();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    EventHandler obj1;
    obj1.subscribeToEvent(CREATION_OBJECT);
    obj1.subscribeToEvent(DELETE_OBJECT);
    EventHandler obj3;
    delete obj2;

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout << "end main" << std::endl;

    return 0;
}
