#include<iostream>

// "2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder. What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?"
int main() // Slow
{
	int sum{2520};
	int remainder{};
	bool done{false};

	while (!done)
	{
		remainder = 0;
		sum += 20;
		for (int i = 10; i <= 20; i = i++)
		{
			if (remainder == 0)
			{
				remainder += sum % i;
				i++;
			}
			else
				i = 21;
		}
		if (remainder == 0)
		{
			done = true;
		}
	}

	std::cout << sum << "\n";
}
