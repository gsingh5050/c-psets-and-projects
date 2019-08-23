// Singh, Gurnoor
// CS211 33B Project 1
#include "ContactBook.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Address.h"
#include "Contact.h"

using namespace std;
 
//function to read contact books from text file and store in a parameter contactbook
void readFile(ifstream& in, ContactBook*& book, int& count)
{
    string input;
    if(!in.eof())
    {
        getline(in, input);
        string line1 = input.substr(0, input.find("|"));
        string line2 = input.substr(input.find("|")+1);
        book = new ContactBook(line1, line2);
        string info[10];
        
        while(input.compare("endofbook|") != 0)
        {
            getline(in, input);
            if(input.compare("endofbook|") == 0)        
                break;
    
            string temp = input;
            for(int i = 0; i < 9; i++)
            {
                info[i] = temp.substr(0, temp.find_first_of("|"));
                temp = temp.substr(temp.find_first_of("|") + 1);        
            }
            info[9] = temp;
            
            Contact* contact = new Contact(info[0], info[1], info[2], info[3]);
            Address add(info[4], info[5], info[6], info[7], info[8], info[9]);
            contact->setAddress(add);
            book->addContact(contact);
        }
        getline(in, input);
        count++;
    }
}


//program to implement a Contact book management system to display menu options to add, delete, modify, and display contact books and contacts
int main()
{
    //creating a ContactBook objects dynamically to store as pointers in an array then reading file
    ContactBook** contacts = new ContactBook*[5];
    int bookCount = 0;
    ifstream myFile;
    myFile.close();
    myFile.open("contactbooks.txt");
    string input; 
    //reading ContactBooks and displaying how many books have been stored from txt file 
    if(myFile.is_open())
    {  
        while(!myFile.eof())
            readFile(myFile, contacts[bookCount], bookCount);
    } 
    myFile.close();
    cout << "***********" << bookCount << " contact books stored from file successfully***********" << endl;

    //using do-while loop until the user chooses to exit the program
    string option;
    do 
    {
    //display menu options and get input for option 
    cout << "\n***************MENU***************" << endl << "Enter a number to select an option:" << endl << "1. Create a new contact book" << endl << "2. Remove a contact book" << endl << "3. Display all contact books" << endl << "4. Merge two contact books" << endl << "5. Select a contact book" << endl << "6. Exit" << endl;
    
    getline(cin, option);
    if(option.compare("1") == 0)
    {   //creating new instance of ContactBook to store in array, cannot store more than 5 books 
        if(bookCount == 5)
        {
            cerr << "***********Error: Maximum number of books reached(" << bookCount << ")***********" << endl;
        }
        else
        {
            contacts[bookCount] = new ContactBook();
            cin >> *contacts[bookCount];
            bookCount++;
        }  
    }
    else if(option.compare("2") == 0)
    {
        //searching for contactbook owner in the array. If found, deletes given contactbook and re-arranges the array, if not found, displaying error
        string input = "";
        cout << "Enter first and last name of contact book owner whose contact book you would like to delete: ";
        getline(cin, input);
        int index = -1;
        for(int i = 0; i < bookCount; i++)
        {
            string name = contacts[i]->getFName() + " " + contacts[i]->getLName();   
            if(input.compare(contacts[i]->getFName()) == 0)
                index = i;
            else if(input.compare(contacts[i]->getLName()) == 0) 
                index = i;
            else if(input.compare(name) == 0) 
                index = i;
        }
        
        if(index == -1)
        {
            cerr << "***********Error: No contact book for that person. Please try again.***********\n\n";
            continue;
        }
        else 
        {   
           contacts[index]->ContactBook::~ContactBook();
           for(int i = index; i < bookCount-1; i++)
               contacts[i] = contacts[i+1];
        
           cout << "***********Contact book deleted successfully.***********" << endl;
           bookCount--;
        }
    }
    else if(option.compare("3") == 0)
    {
        //check if book is empty, if so display error message, otherwise display contactbooks using << operator
        if (bookCount == 0)
        {
            cerr << "***********Error: No contact books have been added yet***********" << endl;
            continue;
        }
        else
        {
            for (int i = 0; i < bookCount; i++)
                cout << *contacts[i] << endl;
        }
        cout << endl << endl;
    }
    else if(option.compare("4") == 0)
    {
        //prompting user for owner name to have contacts merged into and name of owner to be deleted after merge
        string owner1, owner2;
        cout << "Enter first and last name of contact book owner to store merged contacts into: ";
        getline(cin, owner1);
        cout << "Enter first and last name of contact book to be deleted after merging contacts: ";
        getline(cin, owner2);
        
        int index;
        for (int i = 0; i < bookCount; i++)
        {
            string fullName = contacts[i]->getFName() + ' ' + contacts[i]->getLName();
          
            if(owner1.compare(contacts[i]->getFName()) == 0)
                index = i;
            else if(owner1.compare(contacts[i]->getLName()) == 0) 
                index = i;
            else if(owner1.compare(fullName) == 0) 
                index = i;
        }
        
        int index2;
        for (int j = 0; j < bookCount; j++)
        {
            string fullName2 = contacts[j]->getFName() + ' ' + contacts[j]->getLName();
          
            if (owner2.compare(contacts[j]->getFName()) == 0)
                index2 = j;
            else if (owner2.compare(contacts[j]->getLName()) == 0) 
                index2 = j;
            else if (owner2.compare(fullName2) == 0) 
                index2 = j;
        }
        
        //calling merge function on contact book to store contacts into and taking in book to be deleted as parameter 
        contacts[index]->merge(*contacts[index2]);
        //contacts[index]->ContactBook::~ContactBook();
        
        //filling holes in array
        for(int i = index2; i < bookCount; i++)
            contacts[i] = contacts[i+1];

        cout << "***********Contact book deleted successfully.***********" << endl;
        bookCount--;
    }
    
    else if(option.compare("5") == 0)
    {
        //prompting user for owners name in order to access their contact book
        string name;
        cout << "Enter first and last name of contact book owner to access their contacts: ";
        getline(cin, name);
        int index;
        for (int i = 0; i < bookCount; i++)
        {
          string fullName = contacts[i]->getFName() + " " + contacts[i]->getLName();
        
          if (name.compare(contacts[i]->getFName()) == 0) index = i;
          else if (name.compare(contacts[i]->getLName()) == 0) index = i;
          else if (name.compare(fullName) == 0) index = i;
        }

        //creating a ContactBook object that stores a dynamic array of pointers to Contact objects
        ContactBook* list = contacts[index];
        
        //using while loop until the user chooses to exit the program
        string option;
        
        do 
        {
        //display menu options and get input for option 
        cout << "\n***************MENU***************" << endl << "Enter a number to select an option:" << endl << "1. Add New Contact" << endl << "2. Delete Old Contact" << endl << "3. Display Contact Info" << endl << "4. Update Contact    Info" << endl << "5. Display Entire Contact List" << endl << "6. Exit" << endl;
        
        getline(cin, option);
        if(option.compare("1") == 0)
        {
            Contact* x = new Contact();
            cin >> *x;
            list->addContact(x);
            cout << "***********Contact was successfully added***********" << endl;
        }
        else if(option.compare("2") == 0)
        {
            if(list->getSize() != 0)
            {
                string fullName;
                cout << "Enter first and last name of Contact to be deleted: " << endl;
                getline(cin, fullName);
                list->deleteContact(list->searchContact(fullName));
                cout << "***********Contact was successfully deleted***********" << endl;   
            }
            else
                cout << "***********No Contacts in Contact List***********" << endl;
        }
        else if(option.compare("3") == 0)
        {
            if(list->getSize() != 0)
            {
                Contact tmp;
                string displayName;
                cout << "Enter first and last name of Contact to display: " << endl;
                getline(cin, displayName);
                if(list->searchContact(displayName) >= 0)
                {
                    tmp = list->getContact(list->searchContact(displayName));
                    cout << tmp;
                }
                else
                    cout << "***********No Contact with given name in Contact List***********" << endl;
            }
            else
                cout << "***********No Contacts in Contact List***********" << endl;
        }
        else if(option.compare("4") == 0)
        {
            if(list->getSize() != 0)
            {
                string updateName;
                cout << "Enter first and last name of Contact to update: " << endl;
                getline(cin, updateName);
                
                int index = list->searchContact(updateName);
        
                if(index > -1)
                {
                    cout << "Enter new contact information: " << endl;  
                    //dynamic object to store newly inputted contact info
                    Contact* input = new Contact(); 
                    cin >> *input;
                    list->updateContact(input, index);
                }
                else
                {
                    cout << "***********No Contact with given name in Contact List***********" << endl;
                }
            }
            else
                cout << "***********No Contacts in Contact List***********" << endl;
        }
        else if(option.compare("5") == 0)
        {
            //displaying contacts using << operator overreadFile
            cout << *list;
        }
        }while(option.compare("6") != 0);
      }
    }while(option.compare("6") != 0);
  /*
  ofstream out;
  out.open("contactbooks.txt");
  for (int i = 0; i < bookCount; i++)
  {
    out << contacts[i]->getFName() << "|" << contacts[i]->getLName() << endl;
    for (int j = 0; j < contacts[i]->getSize(); j++)
    {
        out << contacts[i]->getContact(j).getFirstName() << "|" << contacts[i]->getContact(j).getLastName() << "|"
                  << contacts[i]->getContact(j).getPhoneNum() << "|" << contacts[i]->getContact(j).getEmail()
                  << "|" << contacts[i]->getContact(j).getAddress().getHome() << "|" << contacts[i]->getContact(j).getAddress().getStreet()
                  << "|" << contacts[i]->getContact(j).getAddress().getApt() << "|" << contacts[i]->getContact(j).getAddress().getCity()
                  << "|" << contacts[i]->getContact(j).getAddress().getState() << "|" << contacts[i]->getContact(j).getAddress().getZip() << endl;
    }
    out << "endofbook|" << endl << endl;
  }
  out.close()
  */
    return 0;
}


