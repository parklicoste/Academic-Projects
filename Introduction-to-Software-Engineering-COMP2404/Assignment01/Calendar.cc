#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#include "Calendar.h"
 Calendar::Calendar(string naam, int no)
{
    cal_name = naam;
    cur_events = no;
}
Calendar::~Calendar()
{
    for(int i=0; i<cur_events; i++)
        delete collection[i];
}
void Calendar::add(Event* eve)
{
    int pos = 0;
    for(int i=0; i<cur_events; i++)
        if((collection[i]->eve_date).lessThan(eve->eve_date))
            pos = i;
    for(int j=cur_events; j>pos;j--)
        collection[j] = collection[j-1];
    collection[pos] = eve;
    cur_events++;

}
void Calendar::print()
{
    for(int i=0; i<cur_events; i++)
        collection[i]->print();
}
