
#include "List.h"
#include <string.h>
#include <iostream>
using namespace std;

List::List(){
	head = NULL;
}

List::~List(){
  Node *currNode, *nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->event;
    delete currNode;
    currNode = nextNode;
  }
}

void List::add(Event* eve){
  Node* tmpNode;
  Node* currNode;
  Node* prevNode;

  tmpNode = new Node;
  tmpNode->event = eve;
  tmpNode->next = NULL;

  currNode = head;
  prevNode = NULL;

	while (currNode != NULL) {
    if (eve->lessThan(currNode->event))
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL) {
    head = tmpNode;
  }
  else {
    prevNode->next = tmpNode;
  }

  tmpNode->next = currNode;
}


void List::print(){
    Node* currNode = head;

    while(currNode != NULL){
        currNode->event->print();
        currNode = currNode->next;
    }
}
/*void List::format(string& str){
  Node* currNode = head;
  Node* nextNode;
  Node* end;
  stringstream ss;
  string temp;
  ss <<"----------FROM HEAD----------" <<endl;
  while(currNode != NULL){
    nextNode = currNode->next;
    currNode->bk->format(temp);
    ss << temp;
    end = currNode; // to store last node for next step
    currNode = nextNode;
   }


   ss <<"----------FROM TAIL----------" <<endl;
   currNode = end;
  while(currNode != NULL){
    nextNode = currNode->prev;
    currNode->bk->format(temp);
    ss << temp;
    currNode = nextNode;
   }
   str = ss.str();
}*/
