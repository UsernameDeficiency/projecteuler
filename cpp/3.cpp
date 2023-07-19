#include<iostream>
#include<cmath>

/* The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143? */
int main()
{
	long number = 600851475143;

	for (int i = 1; i < std::sqrt(number); i = i+2)
	{
		if (number % i == 0)
		{
			number /= i;
		}
	}

	std::cout << number << "\n";
}

