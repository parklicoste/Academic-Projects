// file is person.c

/*
Purpose: contains the functions for processing person records



Revisions:
11/2018 - Doron Nussbaum 	Created




Copyright 2018 Doron Nussbaum


*/



/******************************************************/
// include files
#include "person.h"
#include "patient.h"
#include "employee.h"

/******************************************************/
// function prototypes

void printPerson(PersonRec *person){
    if(person->employeeOrPatient == EMPLOYEE_TYPE)
        printEmployee(person);//calling the print employee function to print employees
    else
        printPatient(person);//calling the print patient function to print employees

}

void printOnlyPatientsFun(PersonRec *person){
    if(person->employeeOrPatient != EMPLOYEE_TYPE)
        printPatient(person); //calling the print patient function to print employees
    else
        return;
}
