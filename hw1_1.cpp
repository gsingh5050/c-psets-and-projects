// Singh, Gurnoor
// CS211 33B Homework 1
#include <iostream>

// function declaration to check prime numbers
bool checkPrimeNum(int);

int main()
{
	int i; 
	int max; // to store max range

	// prompt user for input and store in variable max
	std::cout << "Enter a positive integer: ";
	std::cin >> max;

	// display prime numbers from 2 to max
	std::cout << "Prime numbers:" << "\n";
	for (i = 2; i < max; i++)
	{
		// check if function returns a prime number if so display it
		if (checkPrimeNum(i))
			std::cout << i << " ";
	}
	// check if max input is prime, if so display it
	if (checkPrimeNum(max))
		std::cout << max << " ";
	
	std::cout << "\n";

	return 0;
}


// function to check prime number
bool checkPrimeNum(int n)
{
	bool checkPrime = true;

	// loop to check divisors
	for (int j = 2; j <= n / 2; ++j)
	{
		//check for remainder
		if (n%j == 0)
		{
			checkPrime = false;
			break;
		}
	}
	return checkPrime;
}
