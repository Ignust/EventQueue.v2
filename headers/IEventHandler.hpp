/**
 * Project Untitled
 */


#ifndef _IEVENTHANDLER_H
#define _IEVENTHANDLER_H

class IEventHandler {
public: 
    
/**
 * @param event
 */
virtual void handleEvent(std::shared_ptr<Event> event) = 0;
    
/**
 * @param action
 */
virtual void sendEvent(EAction action) = 0;
private: 
    EventManager* mEventManager;
    
void subscribe();
    
void unsubscribe();
};

#endif //_IEVENTHANDLER_H