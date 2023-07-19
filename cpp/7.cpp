#include <iostream>

// "By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.\nWhat is the 10 001st prime number?"
int main()
{
	//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
	//What is the 10 001st prime number?
	int sum = 2;
	int primePosition = 1;
	bool isPrime = true;

	for (int i = 3; primePosition < 10001; i += 2)//Börjar med att testa om 3 är ett primtal, loopen slutar när primtal nr 10001 hittats
		{
			for (int j = 2; j < i/2; j++)//Testar om i är ett primtal
			{
				if (i % j == 0)//Om i är jämt delbart med j så är det inte ett primtal
				{
					j = i / 2;
					isPrime = false;
				}
			}

			if (isPrime == true)//Om i var ett primtal sparas det
			{
				sum = i;
				primePosition++;
			}

			isPrime = true;
		}

	std::cout << sum << "\n";
}

