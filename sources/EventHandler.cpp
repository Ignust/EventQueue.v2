#include "EventHandler.hpp"
#include "ThreadCout.hpp"

//#include <iostream>

//------------------------------------------------------------------------------------------
EventHandler::EventHandler(std::string name)
    : IEventHandler(name)
//------------------------------------------------------------------------------------------
{
    sendEvent(std::make_shared<Event>(Event(CREATION_OBJECT)));
}

//------------------------------------------------------------------------------------------
EventHandler::~EventHandler()
//------------------------------------------------------------------------------------------
{
    sendEvent(std::make_shared<Event>(Event(DELETE_OBJECT)));
}

//------------------------------------------------------------------------------------------
void EventHandler::handleEvent(std::shared_ptr<Event> event)
//------------------------------------------------------------------------------------------
{
    std::ostringstream os;
          switch (event->action) {
          case DEFAULT:
              os << getName() << ": " << "DEFAULT" << std::endl;
              ThreadCout::get().print(os);
            break;
        case ACTION1:
              os << getName() << ": " << "ACTION1" << std::endl;
              ThreadCout::get().print(os);
            break;
        case CREATION_OBJECT:
              os << getName() << ": " << "CREATION_OBJECT" << std::endl;
              ThreadCout::get().print(os);
            break;
        case DELETE_OBJECT:
              os << getName() << ": " << "DELETE_OBJECT" << std::endl;
              ThreadCout::get().print(os);
            break;

    }
}

