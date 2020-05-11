
#ifndef CALENDAR_H
#define CALENDAR_H
# define MAX_ARR_SIZE 128 
#include "Event.h"
class Calendar
{
    public:
        Calendar(string= "CALENDAR",int=0);
        ~Calendar();
        void add(Event*);
        void print();
    private:                                         
        string cal_name;
        Event* collection[MAX_ARR_SIZE];                              
        int cur_events;  
};
#endif

