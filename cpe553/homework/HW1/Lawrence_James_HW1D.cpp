/*
	Author: James Lawrence
	cite: N/A
*/

#include <iostream>

float find1F() {
	float sum = 0.0;
	for(float denominator = 1.0; denominator <= 100.0; denominator++)
		sum += 1/denominator;
	
	return sum;
}

float find2F() {
	float sum = 0.0;
	for(float denominator = 100.0; denominator >= 1.0; denominator--)
		sum += 1/denominator;
	
	return sum;
}

double find1D() {
	double sum = 0.0;
	for(double denominator = 1.0; denominator <= 100.0; denominator++)
		sum += 1/denominator;

	return sum;
}

double find2D() {
	double sum = 0.0;
	for(double denominator = 100.0; denominator >= 1.0; denominator--)
		sum += 1/denominator;

	return sum;
}


int main() {
	/*
		1. Utilizing a loop, sum the numbers using the float data type:
		   sum1F = 1/1 + 1/2 + 1/3 ... + 1/98 + 1/99 + 1/100 
		   sum2F = 1/100 + 1/99 + 1/98 + ... + 1/3 + 1/2 + 1/1
		   The result should be approximately 5.18.
	*/
	float sum1F = find1F();
	float sum2F = find2F();

	/*
		2. Utilizing a loop, sum the numbers using the double data type:
		   sum1D = 1/1 + 1/2 + 1/3 ... + 1/98 + 1/99 + 1/100 
		   sum2D = 1/100 + 1/99 + 1/98 + ... + 1/3 + 1/2 + 1/1
	*/
	double sum1D = find1D();
	double sum2D = find2D();
	
	/*
		3. Print out sum1F, sum2F, sum1D, sum2D.
		   Print out sum1F - sum2F.
		   Print out sum1D - sum2D.
	*/
	std::cout << "sum1F = " << sum1F << ", sum2F = " << sum2F << std::endl;
	std::cout << "sum1D = " << sum1D << ", sum2D = " << sum2D << std::endl;
	std::cout << "sum1F - sum2F = " << sum1F - sum2F << std::endl;
	std::cout << "sum1D - sum2D = " << sum1D - sum2D << std::endl;

	return 1;
}