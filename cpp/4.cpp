#include<iostream>
#include<string>
#include<list>
#include<algorithm>

/* A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.
Find the largest palindrome made from the product of two 3-digit numbers. */
int main() // Done (but a bit slow...)
{
	int sum{};
	int palindrome{};

	for (int multiplier = 999; multiplier > 100; multiplier--)
	{
		for (int multiplicand = 999; multiplicand > 100; multiplicand--)
		{
			palindrome = multiplier * multiplicand;
			std::string palindrome_str = std::to_string(palindrome);
			std::string reverse_str = palindrome_str;
			std::reverse(reverse_str.begin(), reverse_str.end());
			
			if (palindrome_str == reverse_str && palindrome > sum)
			{
			    sum = palindrome;
			    std::cout << multiplier << " * " << multiplicand <<
			        " = " << palindrome << "\n";
			}
		}
	}
}

