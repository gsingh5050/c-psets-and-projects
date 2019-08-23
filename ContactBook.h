// Singh, Gurnoor
// CS211 33B Project 1
#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <string>
#include "Contact.h"

using namespace std;

//Contact header file declaring values and functions
class ContactBook
{
  private:
      string firstName;
      string lastName;
      Contact** list;
      int count; 
      int size;
      
      //function prototype to sort this array lexicographically
      void sort();
      
       //function prototype to increase capacity of array
      void grow(); 
    
  public:
      ContactBook();
      ContactBook(string first, string last);
      
      //prototypes for copy constructor, destructor, and assignment operator overload 
      ContactBook(const ContactBook& other);
      ~ContactBook();
      ContactBook& operator = (const ContactBook& temp);
      
      //declaring function prototypes
      void addContact(Contact* newContact);
      void deleteContact(int index);
      void updateContact(Contact* newContact, int index);
      int searchContact(string name);
      Contact getContact(int index);
      const int getSize() const; 
      const int getSizeOfArray() const;
      const string getFName() const;
      const string getLName() const;
      void setOwnerName(string fName, string lName);
      void merge(ContactBook&);
      //void displayContacts();
      
      //declaring overload for << operator to displayContacts
      friend ostream& operator << (ostream& print, const ContactBook& list);
      friend istream& operator >> (istream& input, ContactBook& contacts);
};

#endif