#ifndef EVENT_HPP
#define EVENT_HPP

enum EAction {
    DEFAULT = 0,
    ACTION1 = 1,
    CREATION_OBJECT,
    DELETE_OBJECT,
    STOP_MANAGER_EVENTS

};

class Event {
public:
    Event(EAction act) : action(act){}
    EAction action;
};

#endif //_EVENT_HPP
