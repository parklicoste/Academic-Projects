#ifndef LIST_H
#define	LIST_H

#include <string>
using namespace std;

#include "Event.h"

class List{
	class Node { friend class List;
		private:
		  Event* event;
		  Node* next;
	};
	
	private:
	  Node* head;
	
	public:
  	  List();
  	  ~List();
  	  void add(Event*);
      void print();
  	  //void format(string&);
	
};

#endif
