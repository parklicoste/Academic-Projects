#include<iostream>
using namespace std;

#include "SchoolEvent.h"

SchoolEvent::SchoolEvent(string evt, int prt, int d, int m, int y, int h, int mins) : Event(evt , prt, d, m, y, h, mins){
}

bool SchoolEvent::lessThan(Event* eve){

  return (this->eve_date.lessThan(eve->getDate()));

}
