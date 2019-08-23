// Singh, Gurnoor
// CS211 33B Homework 2
#include<iostream>
#include<string>

using namespace std;

//Contact class to contain information of a single personal contact
class Contact
{
private:

	//declaring contact attributes
	string lName;
	string fName;
	string address;
	string phoneNum;
	string email;
public:

	//default constructor setting default values to empty strings
	Contact()
	{
		lName = "";
		fName = "";
		address = "";
		phoneNum = "";
		email = "";
	}

	//parameterized constructor using initializer list
	Contact(string first, string last, string add, string phone, string eMail) : fName(first), lName(last), address(add), phoneNum(phone), email(eMail) {}

	//accessor functions
	string getFirstName()
	{
		return fName;
	}
	string getLastName()
	{
		return lName;
	}
	string getAddress()
	{
		return address;
	}
	string getPhoneNum()
	{
		return phoneNum;
	}
	string getEmail()
	{
		return email;
	}

	//mutator functions
	void setFirstName(string firstN)
	{
		fName = firstN;
	}
	void setLastName(string lastN)
	{
		lName = lastN;
	}
	void setAddress(string addN)
	{
		address = addN;
	}
	void setPhoneNum(string phoneN)
	{
		if (isPhoneNum(phoneN))
			phoneNum = phoneN;
		else
			cout << "Please enter a valid phone number" << endl;
	}
	void setEmail(string emailN)
	{
		if (isEmail(emailN))
			email = emailN;
		else
			cout << "Please enter a valid email address" << endl;
	}

	//function to prompt user for input to solicit information
	void input()
	{
		cout << ("Enter first name:");
		getline(cin, fName);

		cout << ("Enter last name:");
		getline(cin, lName);

		cout << ("Enter address:");
		getline(cin, address);

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
	void output()
	{
		cout << "\n********** Contact Information: **********\nName: " << fName << " " << lName << "\nAddress: " << address << "\nPhone number: " << phoneNum << "\nEmail: " << email << endl;
	}

	//function to check if email string has a "." that comes after "@" symbol
	bool isEmail(string email2)
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

	//function to check if string has 10 characters and all numbers
	bool isPhoneNum(string num)
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
};


int main()
{
	//calling Contact constructors
	Contact person1;
	//Contact person2("John", "Doe" ,"100 abc blvd. Anycity NA", "1234567890", "account@domain.topdomain.com");

	/*
	//testing default constructor
	cout << "Testing default constructor:\n";
	person1.output();
	*/

	/*
	//testing parameterized constructor
	cout << "\nTesting parameterized constructor:\n";
	person2.output();
	*/

	/*
	//testing accessor functions
	cout << "\nTesting accessor functions:\n" << person2.getFirstName() << "\n" << person2.getLastName() << "\n" << person2.getAddress() << "\n" << person2.getPhoneNum() << "\n" << person2.getEmail() << endl;
	*/

	/*
	//testing mutator functions
	cout << "\nTesting mutator functions:\n" << endl;
	person2.setFirstName("New ");
	person2.setLastName("Name");
	person2.setAddress("New address");
	person2.setPhoneNum("0987654321");
	person2.setEmail("changed@email.address");
	person2.output();
	*/

	//testing input function
	person1.input();

	//testing output function
	person1.output();
}