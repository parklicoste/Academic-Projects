#include<iostream>
#include<string>
using namespace std;

#include "Control.h"

Control::Control()
{
    cal = new Calendar();
}
Control::~Control()
{
    delete cal;
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
        string eventName, author;
        int    day, month, year, hours, mins;
        Event* temp_eve;
        v.readEvent(eventName, day, month, year, hours, mins);
        temp_eve = new Event(eventName, day, month, year, hours, mins);
        cal->add(temp_eve);
        }
    }
    v.printCalendar(cal); 
}
