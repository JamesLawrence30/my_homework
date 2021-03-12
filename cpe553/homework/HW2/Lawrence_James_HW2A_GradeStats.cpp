/*
	Author: James Lawrence
	cite: N/A
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath> // for pow() and sqrt() only

double min(double arr[], int N) {

	double min = arr[0];
	for (int i = 0; i < N; i++ ){
		if (arr[i] < min){
			min = arr[i];
		}
	}

	return min;
}

double max(double arr[], int N) {

	double max = arr[0];
	for (int i = 0; i < N; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}

double avg(double arr[], int N) {

	double sum = 0.0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}

	return sum/N;
}

double stdev(double u, double arr[], int N) {

	double innerSum = 0.0;
	for (int i = 0; i < N; i++) {
		innerSum += pow(arr[i] - u, 2);
	}

	return sqrt(innerSum/N);
}

int main() {

	
	// Open file given filename
	std::ifstream f ("grades2.txt");


 	// Read in the first line: N
 	std::string lineBuf;
	getline(f, lineBuf);
	std::istringstream line(lineBuf);

	int N;
	line >> N;
	// std::cout << N << std::endl;


	// Initialize array of length N
	double arr[N];


 	// Read in the rest of the lines: grade0 grade1 ... gradeN	**UNTIL** we collect N numbers
 	int size = N;
	while (getline(f, lineBuf, ' ') && N >= 0) { // Traverse each number in a line separated by ' '
		N--;

		std::istringstream line(lineBuf);
		
		double grade;
		line >> grade;
		
		arr[N] = grade;
	}

/*
	// Print array test
	for (auto x : arr)
		std::cout << x << std::endl;
*/

	std::cout << min(arr, size) << std::endl;

	std::cout << max(arr, size) << std::endl;

	double mean = avg(arr, size);
	std::cout << mean << std::endl;

	std::cout << stdev(mean, arr, size) << std::endl;

	return 1;
}

// need to use professors way (in lecture recording) to intake file
// **use ifstream** **NOT fopen**
// need double (with decimal) precision number intake
// use " f >> grade " format to read space seperated data

// write out calculations for std dev ... etc. , not using math libraries

// std dev = sum of each x minus avg, squared ?