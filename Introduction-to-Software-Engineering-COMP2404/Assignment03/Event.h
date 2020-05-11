#ifndef EVENT_H
#define EVENT_H
#include "Date.h"
class Event
{
    public:
        Event(string, int , int , int , int , int, int);
        void print();
        Date& getDate();
        void setDate(int, int, int, int, int);
        int getPriority();
        virtual bool lessThan(Event*)=0;
    protected:
        string eve_name;
        int priority;
        Date eve_date;
};
#endif
