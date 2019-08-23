// Singh, Gurnoor
// CS211 33B Homework 1
#include <iostream>

// function declaration to check leap year
bool checkLeapYear(int);

int main()
{
	// variables to store user input and to count 5 per line
	int min, max;
	int count;
	bool flag;

	std::cout << "Enter a range of years separated by a space: ";
	std::cin >> min >> max;

	std::cout << "Leap years between " << min << " and " << max << " are:" << "\n";

	// check first range of value to determine if leap year
	if (checkLeapYear(min) == 1)
	{
		count = 1;
		std::cout << min << " ";
	}
	else
	{
		count = 0;
	}

	// output 5 leap years per line
	for (int i = min + 1; i < max; ++i)
	{
		// if i is a leap number, flag will be equal to 1
		flag = checkLeapYear(i);

		// if i is a leap year, increment count and output it
		if (flag)
		{
			count = count + 1;

			if (count <= 5)
			{
				std::cout << i << " ";
			}
			else
			{
				std::cout << "\n" << i << " ";
				count = 1;
			}
		}
	}

	// check last given range of value to determine if leap year
	if (checkLeapYear(max))
	{
		if (count == 5)
			std::cout << "\n" << max << " ";
		else
			std::cout << max << " ";
	}

	std::cout << "\n";

	return 0;
}


// function to check leap year
bool checkLeapYear(int year)
{
	bool result;
	
	// check if divisble by 4
	if (year % 4 == 0)
	{
		// check if its a century year
		if (year % 100 == 0)
		{
			// check if divisible by 400
			if (year % 400 == 0)
				result = true;
			else
				result = false;
		}
		else
			result = true;
	}
	else
		result = false;

	return result;
}