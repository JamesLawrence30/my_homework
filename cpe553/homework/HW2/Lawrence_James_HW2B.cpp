/*
	Author: James Lawrence
	cite: N/A
*/

#include <iostream>

using namespace std;



/*
	2. Write a function called isPrime that returns true if the number is prime 
	   and false if it is not. 
	   The isPrime function will be of bool data type.
*/
bool isPrime(int N) {
	
	if ( N < 2) // 0, 1, and all negative integers are not prime
		return false;

	for (int i = 2; i <= N-1; i++) { // Start at 2 since everything is divisible by 1
		if (N % i == 0)				// End at N-1 since any N % N = 0
			return false;
	}

	return true;
}


int main() {

	// 1. Prompt a user to type in a positive integer from the keyboard.
	int n;
	cout << "Please enter a positive integer:" << endl;
	cin >> n;

	// 3. Output your result to include what number was tested and the result.
	if ( isPrime(n) )
		cout << "The number " << n << " is: PRIME" << endl;
	else
		cout << "The number " << n << " is: NOT PRIME" << endl;

	return 1;
}

// find primes with    n MOD 2..3..4..5 == 0
// run mods through loop of certain length to ensure all bases are checked for