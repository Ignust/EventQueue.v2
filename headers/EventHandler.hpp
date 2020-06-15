/**
 * Project Untitled
 */


#ifndef _EVENTHANDLER_H
#define _EVENTHANDLER_H

#include "IEventHandler.h"


class EventHandler: public IEventHandler {
public: 
    
/**
 * @param event
 */
void handleEvent(std::shared_ptr<Event> event);
    
/**
 * @param event
 */
void sendEvent(std::shared_ptr<Event> event);
};

#endif //_EVENTHANDLER_H