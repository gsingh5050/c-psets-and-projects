// Singh, Gurnoor
// CS211 33B Project 1
#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include "Address.h"

using namespace std;

//Contact header file declaring values and functions
class Contact
{
  private:
    //declaring contact attributes
    string fName;
    string lName;
    string phoneNum;
    string email;
    Address add;
	
  public:
    Contact();
    Contact(string first, string last, string phone, string eMail, Address address);
    Contact(string first, string last, string phone, string eMail);
    
    //accessor functions
    string getFirstName() const;
    string getLastName() const;
    string getPhoneNum() const;
    string getEmail() const;
    Address getAddress() const;
    
    //mutator functions
    void setFirstName(string firstN);
    void setLastName(string lastN);
    void setPhoneNum(string phoneN);
    void setEmail(string emailN);
    void setAddress(Address add1);
    void inputAddress();
    
    //function to check if email string has a "." that comes after "@" symbol
    bool isEmail(string email2);
    
    //function to check if string has 10 characters and all numbers
    bool isPhoneNum(string num);
    
    //function to prompt user for input to solicit information
    void input();
    
    //function to output the state of the Contact
    void out();
    
    //declaring overloads for << and >> operators in Contact class
    friend istream& operator >> (istream& in, Contact& contact);
    friend ostream& operator << (ostream& out, const Contact& contact);
    
    //declaring overloads of <, >, ==, !=, <=, and >= operators in Contact class:
    const bool operator < (const Contact& contact);
    const bool operator > (const Contact& contact);
    const bool operator == (const Contact& contact);
    const bool operator != (const Contact& contact);
    const bool operator <= (const Contact& contact);
    const bool operator >= (const Contact& contact);
};

#endif