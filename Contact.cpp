// Singh, Gurnoor
// CS211 33B Project 1
#include <iostream>
#include <string> 
#include "Contact.h"

using namespace std;

//initializing default and parameterized constructors
Contact::Contact()
{    
  setFirstName("");
  setLastName("");
  setPhoneNum("0000000000");
  setEmail("domain@domain.com");
  Address add;
}
Contact::Contact(string first, string last, string phone, string eMail, Address address)
{
  fName = first;
  lName = last;
  phoneNum = phone;
  email = eMail;
  add = address;
}
Contact::Contact(string first, string last, string phone, string eMail)
{
  fName = first;
  lName = last;
  phoneNum = phone;
  email = eMail;
}

//accessor functions
string Contact::getFirstName() const
{
  return fName;
}
string Contact::getLastName() const
{
  return lName;
}
string Contact::getPhoneNum() const
{
	return phoneNum;
}
string Contact::getEmail() const
{
	return email;
}
Address Contact::getAddress() const
{ 
  return add;
}
//mutator functions
void Contact::setFirstName(string firstN)
{
	fName = firstN;
}
void Contact::setLastName(string lastN)
{
	lName = lastN;
}
void Contact::setPhoneNum(string phoneN)
{
	if (isPhoneNum(phoneN))
	  phoneNum = phoneN;
	else
		cout << "Please enter a valid phone number" << endl;
}
void Contact::setEmail(string emailN)
{
	if (isEmail(emailN))
		email = emailN;
	else
		cout << "Please enter a valid email address" << endl;
}
void Contact::inputAddress()
{
  cin >> add;
}
void Contact::setAddress(Address add1)
{
    add = add1;
}


//function to check if string has 10 characters and all numbers
bool Contact::isPhoneNum(string num)
{
	bool isTrue = true;
	//iterate over string to check if all are digits
	for (int i = 0; i < num.length(); i++)
	{
		if (isdigit(num[i]) < 1)
		{
			isTrue = false;
			cout << "Please enter a valid phone number" << endl;
			phoneNum = "";
			return isTrue;
		}
	}
	//check if length of phone number is 10, if not inform user of error
	if (num.length() != 10)
	{
		isTrue = false;
		cout << "Please enter a valid phone number" << endl;
		phoneNum = "";
		return isTrue;
	}
	return isTrue;
}


//function to check if email string has a "." that comes after "@" symbol
bool Contact::isEmail(string email2)
{
	//check if @ symbol found
	int found = email2.find("@");

	//if found, check if "." found after using string substring function
	if (found != email2.npos)
	{
		found = email2.substr(email2.find("@")).find(".");

		//if found return true
		if (found != email2.substr(email2.find("@")).npos)
			return true;
	}
	//else inform user of error and return false
	email = "";
	cout << "Please enter a valid email address" << endl;
	return false;
}


//function to prompt user for input to solicit information
void Contact::input()
{
	cout << ("Enter first name:");
  getline(cin, fName);

	cout << ("Enter last name:");
	getline(cin, lName);
 
  cout << ("Enter address:") << endl;	
  add.input();

	//check validity of phone number  
	cout << ("Enter phone number:");
	getline(cin, phoneNum);
	if (!isPhoneNum(phoneNum))
		return;

	//check validity of email address
	cout << ("Enter email address:");
	getline(cin, email);
	if (isEmail(email))
		return;
}

//function to output the state of the Contact
void Contact::out()
{
  cout << "\n***********Contact Information:***********\nName: " << getFirstName() << " " << getLastName() << endl;
  cout << "Address:" << endl; 
  add.output();
  cout << "Phone number: " << getPhoneNum() << "\nEmail: " << getEmail() << endl;
}


//overloading >> operator for Contact class
istream& operator >> (istream& in, Contact& contact){
   string fn, ln, ph, em;
   cout << "Enter first name: ";
   in >> contact.fName;
   
   cout << "Enter last name: ";
   in >> ln; contact.setLastName(ln);
  
   cout << "Enter Address: " << endl;
   contact.inputAddress();
   
   cout << "Enter phone number: ";
   in >> ph; 
   if (contact.isPhoneNum(ph))
       contact.setPhoneNum(ph);
       
   cout << "Enter email address:  ";
   in >> em; 
	 if (contact.isEmail(em))
       contact.setEmail(em);

   return in;
}
//overloading << operator for Contact class
ostream& operator << (ostream& out, const Contact& contact)
{   
   cout << "\n***********Contact Information:***********\n";
   out << "First Name: " << contact.fName << endl
      << "Last Name: " << contact.lName << endl
      << "Address:" << endl;
   out << contact.add;
   out << "Phone number: " << contact.phoneNum << endl
      << "Email Address: " << contact.email << endl;

   return out;
}

//overloading <, >, ==, !=, <=, >= operators as members of Contact
const bool Contact::operator < (const Contact& contact)
{
   if (getLastName().compare(contact.getLastName()) < 0) 
   {
       return true;
   }
   else if (getLastName().compare(contact.getLastName()) == 0) 
   { 
       if (getFirstName().compare(contact.getFirstName()) < 0) 
           return true;
   }
   return false;
}

const bool Contact::operator > (const Contact& contact)
{
   if(lName.compare(contact.lName) > 0) 
       return true;
   else if(lName.compare(contact.lName) == 0) 
       if(fName.compare(contact.fName) > 0) 
           return true;
   return false;
}

const bool Contact::operator == (const Contact& contact)
{
   if(lName.compare(contact.lName) == 0 && fName.compare(contact.fName) == 0) 
       return true;
   return false;
}

const bool Contact::operator != (const Contact& contact)
{
   if(lName.compare(contact.lName) == 0 && fName.compare(contact.fName) == 0) 
       return false;
   return true;
}

const bool Contact::operator <= (const Contact& contact)
{
   if(lName.compare(contact.lName) > 0) 
       return false;
   else if(lName.compare(contact.lName) == 0) 
       if(fName.compare(contact.fName) > 0) 
           return false;
   return true;
}

const bool Contact::operator >= (const Contact& contact)  
{
   if(lName.compare(contact.lName) < 0) 
       return false;
   else if(lName.compare(contact.lName) == 0) 
       if(fName.compare(contact.fName) < 0) 
           return false;
   return true;
}