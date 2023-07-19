#include <iostream>

// "The sum of the squares of the first ten natural numbers is,\n1^2 + 2^2 + ... + 10^2 = 385\nThe square of the sum of the first ten natural numbers is,\n(1 + 2 + ... + 10)^2 = 552 = 3025\nHence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.\nFind the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum."
int main()
{
	int sum{0};
	int sqSum{0};

	for (int i = 1; i <= 100; i++)
		sum += i * i;

	for (int i = 1; i <= 100; i++)
		sqSum += i;
	sqSum = sqSum * sqSum;

	sum = sqSum - sum;

	std::cout << sum << "\n";
}

