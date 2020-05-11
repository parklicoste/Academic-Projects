/*
File name is patient.c
Purpose: file contains a function for processing patient records

Revisions
11/2018 - Doron Nussbaum created 





Copyright 2018 Doron Nussbaum

*/

/******************************************************************/
// INCLUDE 



#include "string.h"
#include "stdio.h"
#include "patient.h"


/*****************************************************************/

void printPatient(PersonRec *person)

{
	char s[256];
    char temp[33];
    sprintf(temp,"%s %s",person->firstName, person->familyName);
    sprintf(s,"%-33s dept:%2d days in hospital:%3d severity:%2d daily cost:%3d total cost:%5d",temp, (person->patient).department, (person->patient).numDaysInHospital, (person->patient).severity, (person->patient).dailyCost, ((person->patient).dailyCost * (person->patient).numDaysInHospital));
printf("%s\n",s);
}


