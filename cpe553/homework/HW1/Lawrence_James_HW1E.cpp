/*
	Author: James Lawrence
	cite: N/A
*/

#include <iostream>
#include <math.h>

int main() {
	/*
		1. Prompt a user to type in a positive integer from the keyboard.
		   (Examples: 1, 2, 5, 10, 15)
	*/
	std::cout << "Please enter a positive integer." << std::endl;

	/*
		2. Your program must handle TWO types of incorrect user inputs:
		   A. If the user inputs a negative integer, notify the user and 
		      reprompt to enter a "positive number".
		   B. If the user inputs a decimal value, notify the user and reprompt 
		      to enter a "whole number".
	*/
	double n = 0.0;
	std::cin >> n;

	while( n < 1 || n != std::floor(n) ) {
		if(n < 1) {
			std::cout << "No! Please enter a POSITIVE integer." << std::endl;
			std::cin >> n;	
		}

		if(n != std::floor(n)) {
			std::cout << "No! Please enter a positive INTEGER (\"whole number\")." << std::endl;
			std::cin >> n;	
		}
	}
	
	int input = n;

	/*
		3. Compute the factorial of the positive integer.
		   Example: 5 factorial = 5! = 5 * 4 * 3 * 2 * 1 = 120
	*/
	double factorial = 1;
	while(n > 0) {
		factorial *= n;
		n--;
	}

	/*
		4. Print out both the user input number and the calculated result.
	*/
	std::cout << input << "! = " << factorial;


	return 1;
}


//skip 2b -- need to calculate factorial up to 20 (need a bigger data type than int/float? .../double/long double?)