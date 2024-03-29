#include <iostream>
#include <cmath>

/* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2. There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc. */
int main()
{
	int c;
	unsigned sum{1000};
	
	/* a < b < c, a + b + c = sum, a*a + b*b = c*c.
	 * c = sum - a - b, b < sum - a - b, i.e. b < (sum - a)/2 */
	for (int a = 1; a <= sum / 3; a++)
	{
		for (int b = a + 1; b <= (sum - a) / 2; b++)
		{
			c = sum - a - b;

			if (a*a + b*b == c*c && a+b+c == sum)
			{
				std::cout << "a, b, c = " << a << ", " << b << ", " << c << ". ";
				std::cout << "Product: " << a*b*c << "\n";
			}
		}
	}
}

