#include<iostream>
#include<string>
using namespace std;

#include "Control.h"
#include "WorkEvent.h"
#include "SchoolEvent.h"

Control::Control()
{
    workCal = new Calendar("WORK EVENT CALENDER");
    schoolCal = new Calendar("SCHOOL EVENT CALENDAR");
}
Control::~Control()
{
    delete workCal;
    delete schoolCal;
}
void Control::launch()
{
    int menuSelection;
     while (1) {
    menuSelection = -1;
    v.mainMenu(menuSelection);

    if (menuSelection == 0)
      break;
    else if (menuSelection == 1) {
        string eventName, author, eve_type;
        int    priority,day, month, year, hours, mins;

        v.eventType(eve_type);
        v.readEvent(eventName, priority, day, month, year, hours, mins);

        Event* temp_eve;

        if(eve_type == "Work"){
         // WorkEvent* temp_eve;
          temp_eve = new WorkEvent(eventName, priority, day, month, year, hours, mins);
          workCal->add(temp_eve);
        }

        else{
         // SchoolEvent* temp_eve;
          temp_eve = new SchoolEvent(eventName, priority, day, month, year, hours, mins);
          schoolCal->add(temp_eve);
        }
      }
    }
   // cout<<"\n ========== WORK EVENT ==========\n";
    v.printCalendar(workCal);
    cout<<"\n";
   // cout<<" ========== SCHOOL EVENT ========\n";
    v.printCalendar(schoolCal);
}
