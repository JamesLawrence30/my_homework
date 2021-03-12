/*
	Author: James Lawrence
	cite: N/A
*/

#include <iostream>

int sumSquaresUpTo(int n) {
	int sum = 0;
	for(int i = 1; i <= n; i++)
		sum = sum + i*i;

	return sum;
}

void divideByTwo() {
	for(int i = 100; i > 0; i/=2)
		std::cout << i << " ";
	std::cout << "\n";
}

void countDown() {
	for(int i = 10; i >= 0; i--)
		std::cout << i << " ";
	std::cout << "\n";
}


int main() {

	// 1*1 + 2*2 + 3*3 + 4*4 + 5*5 = ???
	std::cout << sumSquaresUpTo(5) << std::endl;
	std::cout << sumSquaresUpTo(7) << std::endl;

	// write a for loop that prints 100, 50, 25, 12, 6, 3, 1 (keep dividing by 2)
	divideByTwo();

	// write a for loop that counts 10 9 8 7 6 5 4 3 2 1 0
	countDown();

	return 1;
}