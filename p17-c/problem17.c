/*
 Project Euler problem 17
 If all the numbers from 1 to 1000 inclusive were
 written out in words, how many letters would be used?
 Ignore spaces and hyphens but count "and"
*/
#include<stdio.h>

enum numlengths {
	one = 3,
	two = 3,
	three = 5,
	four = 4,
	five = 4,
	six = 3,
	seven = 5,
	eight = 5,
	nine = 4,
	ten = 3,
	eleven = 6,
	twelve = 6,
	thirteen = 8,
	fourteen = 8,
	fifteen = 7,
	sixteen = 7,
	seventeen = 9,
	eighteen = 8,
	nineteen = 8,
	twenty = 6,
	thirty = 6,
	forty = 5,
	fifty = 5,
	sixty = 5,
	seventy = 7,
	eighty = 6,
	ninety = 6,
	hundred = 7,
	onethousand = 11,
	and = 3
};


int count_single(int i)
{
	int length;
	
	switch (i) {
		case 0 :
			length = 0;
			break;
		case 1 :
			length = one;
			break;
		case 2 :
			length = two;
			break;
		case 3 :
			length = three;
			break;
		case 4 :
			length = four;
			break;
		case 5 :
			length = five;
			break;
		case 6 :
			length = six;
			break;
		case 7 :
			length = seven;
			break;
		case 8 :
			length = eight;
			break;
		case 9 :
			length = nine;
			break;
			}
	return length;
}

int count_ten(int i)
{
	int length;

	if (i < 20) {
		switch (i) {
			case 10 :
				length = ten;
				break;
			case 11 :
				length = eleven;
				break;
			case 12 :
				length = twelve;
				break;
			case 13 :
				length = thirteen;
				break;
			case 14 :
				length = fourteen;
				break;
			case 15 :
				length = fifteen;
				break;
			case 16 :
				length = sixteen;
				break;
			case 17 :
				length = seventeen;
				break;
			case 18 :
				length = eighteen;
				break;
			case 19 :
				length = nineteen;
				break;
		}
	}
	// i >= 20
	else {
		switch (i - (i % 10)) {
			case 20 :
				length = twenty;
				break;
			case 30 :
				length = thirty;
				break;
			case 40 :
				length = forty;
				break;
			case 50 :
				length = fifty;
				break;
			case 60 :
				length = sixty;
				break;
			case 70 :
				length = seventy;
				break;
			case 80 :
				length = eighty;
				break;
			case 90 :
				length = ninety;
				break;
		}

		// Count last digit
		if (i % 10 != 0) {
			length += count_single(i % 10);
		}
	}

	return length;
}

int count_hundred(int i)
{
	int length;

	length = count_single(i / 100); // Count first digit
	if (i % 100 == 0) {
		length += 7; // Count "hundred"
	}
	else {
		length += 10; // Count "hundred and"
		length += count_ten(i % 100); // Count second and third digits
	}
	return length;
}

int main()
{
	/*
	 one, two, three, four, five, six, seven, eight, nine, ten, eleven,
	 twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, 
	 nineteen, twenty..., thirty..., forty..., fifty..., sixty..., seventy...,
	 eighty..., ninety..., one hundred, one hundred and..., ..., one thousand
	*/
	// Count up to 4 digits (1000) and associate each digit
	// according to its position in the number, e.g.
	// 0942 = nine hundred and forty-two has length
	// (0) + (4 + 7 + 3) + (5) + (3)
	int length = 0;

	for (int i = 1; i <= 1000; i++) {
		// Extract each digit from the current number
		if (i / 10 == 0) { // Length 1
			length += count_single(i);
		}

		else if (i / 100 == 0) { // Length 2
			length += count_ten(i);
		}

		// TODO: Reuse results from above
		else if (i / 1000 == 0) { // Length 3
			length += count_hundred(i);
		}

		else { // i = 1000
			length += onethousand;
		}
	}
	printf("Total length: %i\n", length);
}
