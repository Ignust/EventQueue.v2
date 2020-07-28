#include "EventHandler.hpp"
#include "ThreadCout.hpp"

//------------------------------------------------------------------------------------------
EventHandler::EventHandler(std::string name, std::shared_ptr<IEventHandler> obj)
    :IEventHandler(name,obj)
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

ostringstream os;
      switch (event->action) {
      case DEFAULT:
          os << getName() << ": " << "DEFAULT" << endl;
          ThreadCout::get().print(os);
        break;
    case ACTION1:
          os << getName() << ": " << "ACTION1" << endl;
          ThreadCout::get().print(os);
        break;
    case CREATION_OBJECT:
          os << getName() << ": " << "CREATION_OBJECT" << endl;
          ThreadCout::get().print(os);
        break;
    case DELETE_OBJECT:
          os << getName() << ": " << "DELETE_OBJECT" << endl;
          ThreadCout::get().print(os);
        break;


    }
}

