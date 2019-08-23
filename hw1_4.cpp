// Singh, Gurnoor
// CS211 33B Homework 1
#include <iostream>

// function declaration to reverse a given integer
int reverseInt(int); 

int main()
{
	int input = 0;

	// continuously ask user for a positive integer and output its reverse, until user enters a negative integer
	do
	{
		std::cout << "Please enter a positive integer:\n";
		std::cin >> input;

		input = reverseInt(input);

		std::cout << "Reversed integer: " << input << "\n";
	} while (input > 0);

	return(0);
}

// function to reverse an integer and return it
int reverseInt(int num)
{
	int reverse = 0;
	int remainder;

	// take modulus of input to get first reversed value. Then multiply current reverse value by 10 and add remainder, to store into reverse variable.
	// Then divide input by 10 to delete last reversed value
	while (num > 0)
	{
		remainder = num % 10;
		reverse = reverse * 10 + remainder;
		num = num / 10;
	}

	return reverse;
}