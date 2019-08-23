// Singh, Gurnoor
// CS211 33B Homework 1
#include <iostream>

// function declaration to check perfect numbers
bool checkPerfectNum(int);

int main()
{
	// to store, maximum range
	int max; 

	std::cout << "Enter a positive integer: ";
	std::cin >> max;

	// print perfect numbers from 2 to n
	std::cout << "Perfect numbers:" << "\n";
	
	for (int i = 2; i <= max; i++)
	{
		// check if function returns a perfect number if so display it
		if (checkPerfectNum(i))
			std::cout << i << " ";
	}

	std::cout << "\n";

	return 0;
}

// function to check perfect number
bool checkPerfectNum(int num)
{
	int div, sum = 0;

	// check given numbers divsors and keep track of sum of divisors
	for (int i = 1; i < num; i++)
	{
		div = num % i;
		if (div == 0)
			sum = sum + i;
	}

	if (sum == num)
		return true;
	else
		return false;
}