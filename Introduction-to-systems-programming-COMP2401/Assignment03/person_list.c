
/*
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list

 Revisions
 Doron Nussbaum 2018





 Copyright 2018 Doron Nussbaum

 */

/******************************************************************/
// INCLUDE

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "employee.h"
#include "patient.h"
#include "person_list.h"

/************************************************************************/
// Define




/************************************************************************/

/*
Purpose: deletes the first node that matches the family namne
input
head - the head of the linked list
familyName - family name of person

inputoutput
head - modified head in case the first record was deleted
data - the data of the deleted node.  Return NULL if node was not deleted

return
0 - if a node was deleted
1 - if a node was not deleted


*/
int deleteNodeByFamilyName(PersonList **head, char *familyName, PersonRec **data)
{
    PersonList* currNode =(PersonList*)malloc(sizeof(PersonList));// making a temporary node to traverse and find the right person
    currNode = *head;
    PersonList* prevNode = NULL;


	// add code
    while(currNode != NULL)
    {
        if(!strcmp(currNode->data->familyName,familyName))// if the name matches
            break;
        prevNode = currNode;
        currNode = currNode->next;
    }

    if(currNode == NULL){// person with family name not found
        return 1;
    }

    if(prevNode == NULL && currNode != NULL){ // first Node matched with familyName
       *head = currNode->next;
     }

    else{
      prevNode->next = currNode->next; // delete after part
    }

    *data = currNode->data;
    free(currNode);
    return 1;


}





/************************************************************************/
/*
Purpose: prints all the person in the list that their family name matches the input familyName

input
head - the head of the list
familyName - familyName to be matched

output
None

Return
None
*/


void printAllByName(PersonList *head, char *FamilyName)
{
	// add code
    while(head != NULL){
        if(strcmp(FamilyName, head->data->familyName)==0)// comparing the names
            printPerson(head->data); // calling the print function in person.h
        head = head->next;// updating the head
    }


}


/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printListFun(PersonList *head, void(*printFun)(PersonRec *data))
{
	// add code
    while(head != NULL){
        printFun((head->data)); // calling the fuction whose pointer was passed in parameter
        head = head->next;// updating to next
    }



}

/************************************************************************/

/*
Purpose: insert a new node into the list in a lexcicographic order

input
data - a person record

input/output
head - head of linked list

return
A pointer to the node that was allocated.
NULL - if the operation was not successful

NULL - if the operation was not successful

*/


PersonList *insertByName(PersonList **head, PersonRec *data)
{
    if(data == NULL) return NULL; // if there is nothing in data null

    else{
      PersonList* currNode; //current node
      PersonList* tmpNode; //temporary node
      PersonList* prevNode; // the previous node

      tmpNode = (PersonList*)malloc(sizeof(PersonList)); // allocating size of list to temporary node that is added in list sooner
      tmpNode->data = data; // allocating the data in temporary node
      tmpNode->next = NULL;

      currNode = *head;
      prevNode = NULL;

      while(currNode != NULL){// traversing the list, finding the right place
          if(strcmp(currNode->data->familyName,data->familyName)==1)
              break;
          prevNode = currNode;
          currNode = currNode->next;
          }

      if(prevNode == NULL){
          *head = tmpNode;
        }
      else{
          prevNode->next = tmpNode;
        }

      tmpNode->next = currNode;
      return tmpNode;// success in adding the node and returning
      }
}

/************************************************************************/

/*
Purpose: delete the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
data - a person record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteNodeByName(PersonList **head, PersonRec **data)// this function is neither declared in pdf file nor in person_list.h
{
	// add code

	return(0);
}


/***********************************************************************/
/*
Purpose: deletes all nodes from the list.  Note that the function should not need to release
the data field (it is up to the calling program)
input/output
head - the head of the list (set to NULL)


*/


void deleteList(PersonList **head)
{
	// add code
    PersonList *prevNode = NULL;
    while(*head != NULL){    // will run until find end of list or null pointer
        prevNode = *head;
        *head = (*head)->next; //updating to next
        free(prevNode);// deleting the links of node with deleting the data
    }



}








/************************************************************************/

/************************************************************************/
/************************************************************************/
/************************************************************************/
/************************************************************************/
/************************************************************************/

// CODE THESE FUNCTIONS IF  NEEDED
/*
Purpose: insert a new node into the list as the first element
input
data - a person record

input/output
head - head of linked list

return
A pointer to the node that was allocated.
NULL - if the operation was not successful

*/


PersonList *insertFirst(PersonList **head, PersonRec *data)
{
	// add code



}


/************************************************************************/
/*
Purpose: insert a new node into the list after the given node

Input
node - the node after which the new node must be added to the list
data - a person record


return
A pointer to the node that was allocated.
NULL - if the operation was not successful

*/


PersonList *insertAfter(PersonList *node, PersonRec *data)
{
	// add code


}

/************************************************************************/
/*
Purpose: create a new node and insert it into the end of the list
Input
head - the head of the list
data - a person record


return
A pointer to the node that was allocated.
NULL - if the operation was not successful

*/


PersonList *insertLast(PersonList **head, PersonRec *data)
{
	// add code


}





/************************************************************************/

/*
Purpose: delete the record after the given node
Input
node - a node in the list

output
data - a person record

return
0 if node was deleted
1 if node was not deleted (either input node is NULL or input node was the lastnode in the list)

*/



int deleteAfter(PersonList *node, PersonRec **data)

{
    // add code

}

/************************************************************************/

/*
Purpose: delete the first node in the linked list
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
data - a person record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteFirst(PersonList **head, PersonRec **data)
{
	// add code


}
