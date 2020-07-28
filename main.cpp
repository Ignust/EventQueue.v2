#include <iostream>
#include <thread>
#include <chrono>

#include "ThreadCout.hpp"
#include "EventHandler.hpp"


void test();

int main()
{
    ThreadCout::get().print("start main");

    EventHandler* obj1 = new EventHandler("obj1");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    EventHandler obj2("obj2");
    obj2.subscribeToEvent(CREATION_OBJECT);
    obj2.subscribeToEvent(DELETE_OBJECT);
    EventHandler obj3("obj3");
    delete obj1;


    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    ThreadCout::get().print("end main");

    return 0;
}


void test()
{
    EventHandler* obj1 = new EventHandler("obj1");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    EventHandler obj2("obj2");
    obj2.subscribeToEvent(CREATION_OBJECT);
    obj2.subscribeToEvent(DELETE_OBJECT);
    EventHandler obj3("obj3");
    delete obj1;
}
