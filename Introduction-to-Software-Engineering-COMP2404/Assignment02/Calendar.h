
#ifndef CALENDAR_H
#define CALENDAR_H
# define MAX_ARR_SIZE 128 
#include "Event.h"
#include "List.h"
class Calendar
{
    public:
        Calendar(string= "CALENDAR",int=0);
        ~Calendar();
        void add(Event*);
        void print();
    private:                                         
        string cal_name;
        List* collection;                              
        int cur_events;  
};
#endif

