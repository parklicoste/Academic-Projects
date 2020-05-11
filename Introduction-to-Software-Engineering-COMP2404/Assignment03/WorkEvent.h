#ifndef WORKEVENT_H
#define WORKEVENT_H

#include "Event.h"

class WorkEvent : public Event{
    public:
        WorkEvent(string, int, int, int, int, int, int);
        bool lessThan(Event*);
};
#endif
