/*
	Author: James Lawrence
	cite: N/A
*/

#include <iostream>
#include <cmath>

int main() {

	// 1.
	int limit;
	std::cout << "Enter a small, positive integer" << std::endl;
	std::cin >> limit;

	// 2.
	float sum = 0.0;
	for (float i = 1; i <= limit; i++) {
		sum += 1/(i*i);
	}

	// 3.
	float result1 = sqrt(6 * sum);

	// 4.
	std::cout << "result1 = " << result1 << std::endl;

	// 5.
	std::cout << "Enter a large, positive integer" << std::endl;
	std::cin >> limit;

	sum = 0.0;
	for (float i = 1; i <= limit; i++) {
		sum += 1/(i*i);
	}
	float result2 = sqrt(6 * sum);

	for (float i = limit; i > 0; i--) {
		sum += 1/(i*i);
	}
	float result3 = sqrt(6 * sum);
	

	// 6.
	std::cout << "result2 = " << result2 << std::endl;
	std::cout << "result3 = " << result2 << std::endl;

	return 1;
}

// use float
// go beyond 1/1000 but determine how far needed (and in which 'direction') till convergence
// aka dont need to go to 1/infinity just till convergence