#ifndef CONTROL_H
#define CONTROL_H

#include "Calendar.h"
#include "View.h"

class Control
{
    Calendar* workCal;
    Calendar* schoolCal;
    View v;
    public:
        Control();
        ~Control();
        void launch();

};
#endif
