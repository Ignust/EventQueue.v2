#ifndef EVENT_HPP
#define EVENT_HPP

enum EAction {
    DEFAULT = 0,
    ACTION1 = 1
};

class Event {
public:
    EAction action;
};

#endif //_EVENT_HPP
