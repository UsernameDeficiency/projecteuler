#include<iostream>
#include<array>
#include<cmath>

// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17. Find the sum of all the primes below two million.
int main() // Very slow solution
{
	// Use the sieve of Eratosthenes to find primes. This implementation seems quick enough but can be optimized.
	size_t sum{0};
	const size_t max{2000000};
	std::array<bool, max + 1> sieve;
	sieve.fill(true);

	for (size_t i = 2; i <= max; i++)
	{
		if (sieve.at(i)) // i prime, remove multiples
		{
			sum += i;
			for (size_t j = i; j <= max; j += i)
				sieve.at(j) = false;
		}
	}
	
	std::cout << sum << "\n";
}

