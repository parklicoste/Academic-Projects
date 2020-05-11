
#ifndef EVENT_H
#define EVENT_H
#include "Date.h"
class Event
{
    public:
        Date eve_date;
        Event(string, int , int , int , int , int);
        void print();
        Date getDate();
        void setDate(int, int, int, int, int);
    private:
        string eve_name;
};
#endif

