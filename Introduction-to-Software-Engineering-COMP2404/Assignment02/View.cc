#include<iostream>
using namespace std;
#include "View.h"

int View :: mainMenu(int& selection)
{
    int numOptions = 1;

  cout << endl;
  cout << "(1) Add Event" << endl;
  cout << "(0) Exit" << endl;

  while (selection < 0 || selection > numOptions) {
    cout << "Enter your selection: ";
    cin  >> selection;
  }

  return selection;

}
void View::readEvent(string& eventName, int& day, int& month, int& year,int& hours, int& mins)
{   
      cout<<"event name: ";
      cin.ignore();
      getline(cin,eventName);
      cout << "day:   ";
      cin  >> day;
      cout << "month: ";
      cin  >> month;
      cout << "year:  ";
      cin  >> year;
      cout<<"hours:   ";
      cin>>hours;
      cout<<"mins:    ";
      cin>>mins;

}
void View::printCalendar(Calendar* cal)
{
  cal->print();

}

