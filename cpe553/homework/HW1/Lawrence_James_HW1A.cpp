/*
	Author: James Lawrence
	cite: N/A
*/

#include <iostream>

int main() {
	// 1. Prompt the user to input a positive integer from the keyboard. 
	   // (Example: "Please enter a positive integer: ")
	std::cout << "Please enter a positive integer." << std::endl;

	// 2. Read in the positive integer from keyboard. 
	   // (Example n = 5) 
	   // (Error handling for incorrect input types is not required)
	int n = 0;
	std::cin >> n;

	if(n > 0)
		std::cout << n;
	else {
		std::cout << "Negative entered." << std::endl;
		return 0;
	}

	// 3. If the number is odd, multiply it by 3 and add 1.
	   // If the number is even, divide by 2.

	   // Repeat these rules on each result until the number converges to 1. 

	   // If done properly, any positive integer will converge to 1.
	while(n != 1) {
		if(n % 2 == 0)
			n /= 2;
		else
			n = (n*3) + 1;

	// 4. Display ALL intermediate values with either a space, tab, or newline 
	   // between them, and the final result.
	   std::cout << " " << n;
	}
	

	return 1;
}


//hw1a while number not 1 .. while >= 1 (?) .. while loop containing if statement
//prompt user for input num using cin