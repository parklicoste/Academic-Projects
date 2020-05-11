#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

#include"Event.h"

Event::Event(string naam, int d, int m, int y, int h, int mins)
{   
    eve_name = naam;
    setDate(d, m, y, h, mins);
}
void Event::print()
{
    cout<<setfill(' ')<<setw(20)<<left<<eve_name;
    getDate().printLong();
}
Date Event::getDate()
{
    return(eve_date);
}
void Event::setDate(int d,int m,int y, int h, int mins)
{
    eve_date.set(d,m,y,h,mins);
}


