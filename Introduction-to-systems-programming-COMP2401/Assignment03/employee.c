// file is person.c

/*
Purpose: contains the functions for processing employree records



Revisions:
11/2018 - Doron Nussbaum 	Created




Copyright 2018 Doron Nussbaum


*/



/******************************************************/
// include files 


#include "stdio.h"
#include "employee.h"



/******************************************************/

void printEmployee(PersonRec *person)

{
	char s[256];
    char temp[33];
    sprintf(temp,"%s %s",person->firstName, person->familyName);
    sprintf(s,"%-33s dept:%2d salary:%9.2f position:%2d years of service:%4d salary to-date:%10.2f", temp, (person->emp).department, (person->emp).salary, (person->emp).position, (person->emp).yearsOfService, ((person->emp).yearsOfService * (person->emp).salary));
    printf("%s\n",s);
	return;
}
