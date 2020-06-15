/**
 * Project Untitled
 */


#ifndef _EVENTMANAGER_H
#define _EVENTMANAGER_H

class EventManager {
public: 
    
/**
 * @param user
 */
void subscribe(IEventHandler* user);
    
/**
 * @param user
 */
void unsubscribe(IEventHandler* user);
    
/**
 * @param event
 */
void pushEvent(std::shared_ptr<Event> event);
private: 
    std::list<IEventHandler*> mEventHandlerList;
    std::queue<std::shared_ptr<unEvent>> mEventQueue;
    std:: mutex mMutex;
    
void manageEvents();
};

#endif //_EVENTMANAGER_H