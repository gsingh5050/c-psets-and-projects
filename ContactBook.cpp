// Singh, Gurnoor
// CS211 33B Project 1
#include <iostream>
#include <string>
#include <cstdlib>
#include "ContactBook.h"

using namespace std;

//initializing default constructors
ContactBook::ContactBook()
{   
    firstName = "";
    lastName = "";
    list = new Contact*[10];
    count = 0;
    size = 10;
}

//initializing default constructors
ContactBook::ContactBook(string first, string last)
{   
    firstName = first;
    lastName = last;
    list = new Contact*[10];
    count = 0;
    size = 10;
}

//copy constructor overload for deep copies
ContactBook::ContactBook(const ContactBook& temp)
{ 
    size = temp.size;
    count = temp.count;
    
    list = new Contact*[size];
    for(int i = 0; i < count; i++)
    {
      list[i] = new Contact(*(temp.list[i])); //makes a copy 
    }
}

//destructor for ContactBook class
ContactBook::~ContactBook()
{ 
    for(int i = 0; i < count; i++)
    {
        if(list[i] != NULL)
            delete list[i]; //removes all the objects in the array
    }
    if(list != NULL)
        delete[] list; //removes the array of pointers
}

//assignment operator overload
ContactBook& ContactBook::operator = (const ContactBook& temp)
{
    //check if this ContactBook and the parameter is the same, if so return original ContactBook
    if(this != &temp)
    { 
        if(list != NULL)
        {
            for(int i = 0; i < count; i++)
            {
              delete list[i];
            }
            delete[] list;
        }

        //copying objects into new array
        firstName = temp.firstName;
        lastName = temp.lastName;
        count = temp.count;
        size = temp.size;
        list = new Contact*[size];
  
        for(int i = 0; i < count; i++)
        {
            list[i] = new Contact(*(temp.list[i]));
        }
    }
    return *this;
}

//function to double the capacity of the array if needed
void ContactBook::grow()
{
   size = size*2;
   Contact** temp = new Contact*[size];

   for(int i = 0; i < size; i++)
       temp[i] = NULL; 
   
   for(int i = 0; i < size; i++)
      temp[i] = list[i];
   
   delete[] list;
   list = temp;
}

//function to sort the array lexicographically
void ContactBook::sort()
{   
   int index = 0;
   for (int i = 0; i < count; i++)
   {
      string test = list[i]->getLastName();
      for (int j = i; j < count; j++)
      {
         if (test.compare(list[j]->getLastName()) > 0)
         {
            test = list[j]->getLastName();
            index = j;
         }
         else if (test.compare(list[j]->getLastName()) == 0)
         {
            string test2 = list[i]->getFirstName();
            if (test2.compare(list[j]->getFirstName()) > 0)
            {
               Contact* temp2 = list[i];
               list[i] = list[j];
               list[j] = temp2;
            }
         }
      }
      Contact* temp = list[i];
      list[i] = list[index];
      list[index] = temp;
   }
}


//function to merge two ContactBooks
void ContactBook::merge(ContactBook& temp)
{

    for (int i = 0; i < temp.getSize(); i++)
    {
          this->addContact(temp.list[i]);
    }
    //sort();
    /*
    if(temp.getSize() > list->getSize())
    {
        int cap = temp.Contact::getSize() + list.Contact::getSize();
        if(cap > temp.getSizeOfArray())
        {
            grow();
        }
        int count = 0;
        for(int i = count; i < list.getSize(); i++)
        {
            temp[i] = list[count];
        
        }
          
        delete[] list;
        list = temp;
          
        sort();
    }
    */    
}


//function to add a contact to the array stack of Contacts
void ContactBook::addContact(Contact* newContact)
{
    if(count == size)
        grow();
    
	  list[count] = newContact;
	  count++;
    sort();
}

//function to delete a Contact from a given index
void ContactBook::deleteContact(int index)
{
    //check if index is out of bounds, then copy all elements except Contact to be deleted.
    if(index < count && index >= 0 && count > 0)
    {
        delete list[index];
        for (int i = index; i < count; i++)
            list[i] = list[i+1];
         
        count--;
    }
    else
        cerr << "Error: Invalid index." << endl;
}

//function to update a given Contact's info, 
void ContactBook::updateContact(Contact* newContact, int index)
{   
    if (index > -1 && index < count)
    {
        delete list[index];
        list[index] = newContact;
        cout << "***********Contact was successfully updated***********" << endl;
        sort();
    }
    else 
        cerr << "Error: Invalid index." << endl;
}

//function to return given index of a Contact, if not found returns -1
int ContactBook::searchContact(string name)
{
    for (int i = 0; i < count; i++){
    	  string firstLast = list[i]->getFirstName() + ' ' + list[i]->getLastName();
    
    //converting each letter of the full name to uppercase, in order to compare   
    for(int j = 0; j < firstLast.length(); j++)
        firstLast[j] = toupper(firstLast[j]);
        
    for(int k = 0; k < name.length(); k++)
        name[k] = toupper(name[k]);
      
    //checking if there is a match, if so returns index
  	if (name.compare(list[i]->getFirstName()) == 0) 
        return i;
  	else if (name.compare(list[i]->getLastName()) == 0) 
        return i;
  	else if (name.compare(firstLast) == 0) 
        return i;
    }
    return -1;
}

//function to return a Contact at given index
Contact ContactBook::getContact(int index)
{
    if(index < count && index >= 0)
        return *list[index];
    else
        cerr << "Error: Invalid index." << endl;
}

//function to return the ContactBook owner's first name
const string ContactBook::getFName() const
{
    return firstName;

}

//function to return the ContactBook owner's last name
const string ContactBook::getLName() const
{
    return lastName;

}

void ContactBook::setOwnerName(string fName, string lName)
{
    firstName = fName;
    lastName = lName;

}

//accessor function to return the current size of the ContactBook
const int ContactBook::getSize() const
{
    return count;
}

//accessor function to return the current size of the ContactBook
const int ContactBook::getSizeOfArray() const
{
    return size;
}

ostream& operator << (ostream& print, const ContactBook& list){ //replaces displayAll function
   if (list.getSize() == 0){
      print << "Error: There are no contacts in " << list.firstName << " " << list.lastName << "'s contact book.\n";
      return print;
   }
   print << "*************" <<list.firstName << " " << list.lastName << "'s Contact Book:*************\n";
   for (int i = 0; i < list.getSize(); i++){
      print << *list.list[i] << endl;
   }
   print << endl << endl;
   return print;
}

istream& operator >> (istream& input, ContactBook& contacts)
{
   cout << "Please enter the first name of this contact book's owner.: ";
   getline(input, contacts.firstName);
   cout << "Please enter the last name of this contact book's owner.: ";
   getline(input, contacts.lastName);

   cout << "Contact book created successfully. The owner is now " << contacts.firstName << " " << contacts.lastName << ".\n";
  
   return input;
}
/*
//function to display all Contacts in the list
void ContactBook::displayContacts()
{
    if(count == 0)
    {
        cout << "***********No Contacts in Contact List***********" << endl;
        return;
    }     
    cout << "***********Displaying all contacts***********" << endl;
    for(int i = 0; i < count; i++)
    {
    cout << list[i];
     //list[i].out();
    } 
}
*/