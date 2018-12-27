#include<stdio.h>

/*
 Project Euler problem 12
 Find the first triangle number with over 500 divisors	
*/

int num_divisors(int num);

int main ()
{
	unsigned int curr_number  = 1; // Largest num in current triangle num
	unsigned long int triangle_num = 1; // Current triangle num
	
	while (num_divisors(triangle_num) <= 501)
	{
		curr_number++;
		triangle_num += curr_number; // Calc next triangle num 
	}
	// Print result
	printf("The triangle number %lu was found to have %d divisors.\n",
		triangle_num, num_divisors(triangle_num));
}

// num_divisors returns the number of
// divisors of num > 0, including 1 and num
int num_divisors(int num)
{
	// This for loop checks an unnecessarily large amount of numbers!
	int divisors = 2;
	for (int i = 2; i * i <= num; i++)
	{
		// Divisor found?
		if (num % i == 0)
		{
			divisors += 2;
			// Do this if outside of the loop!
			if (i * i == num)
			{
				// Largest divisor pair found,
				// decrement divisors (since they were identical)
				// and exit loop
				divisors--;
				break;
			}
		}
	}
	return divisors;
}

