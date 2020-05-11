#include<iostream>
using namespace std;

#include "WorkEvent.h"

WorkEvent::WorkEvent(string evt, int prt, int d, int m, int y, int h, int mins) : Event(evt , prt, d, m, y, h, mins){
}

bool WorkEvent::lessThan(Event* eve){
  return (this->priority < eve->getPriority());
}
