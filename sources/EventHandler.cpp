#include "EventHandler.hpp"

#include <iostream>

//------------------------------------------------------------------------------------------
EventHandler::EventHandler()
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
EventHandler::~EventHandler()
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
void EventHandler::handleEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    switch (event->action) {
    case DEFAULT:
        std::cout << "DEFAULT" << std::endl;
        break;
    case ACTION1:
        std::cout << "ACTION1" << std::endl;
        break;
    case CREATION_OBJECT:
        std::cout << "CREATION_OBJECT" << std::endl;
        break;
    case DELETE_OBJECT:
        std::cout << "DELETE_OBJECT" << std::endl;
        break;


    }
}

