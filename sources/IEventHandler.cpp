/**
 * Project Untitled
 */


#include "IEventHandler.h"

/**
 * IEventHandler implementation
 */


/**
 * @param event
 */
virtual void IEventHandler::handleEvent(std::shared_ptr<Event> event) {

}

/**
 * @param action
 */
virtual void IEventHandler::sendEvent(EAction action) {

}

void IEventHandler::subscribe() {

}

void IEventHandler::unsubscribe() {

}