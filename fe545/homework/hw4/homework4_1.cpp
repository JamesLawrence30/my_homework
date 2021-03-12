// I pledge my Honor that I have abided by the Stevens Honor System.
//

#include <iostream>
#include <time.h> // clock_t, clock(), CLOCKS_PER_SEC

using namespace std;

int main()
{
	double* arr; // initialize pointer to double
	clock_t startClock, endClock, runClock; // declare new timer

	startClock = clock(); // record start time
	// allocate array and save pointer in arr 10,000 times
	for (int i = 0; i < 10000; i++) {
		arr = new double[100];
	}
	endClock = clock(); // record end time

	runClock = endClock - startClock;
	cout << "double[100] total clock cycles: " << runClock << endl;

	startClock = clock(); // record start time
	// allocate array and save pointer in arr 10,000 times
	for (int i = 0; i < 10000; i++) {
		arr = new double[200];
	}
	endClock = clock(); // record end time

	runClock = endClock - startClock;
	cout << "double[200] total clock cycles: " << runClock << endl;

	startClock = clock(); // record start time
	// allocate array and save pointer in arr 10,000 times
	for (int i = 0; i < 10000; i++) {
		arr = new double[400];
	}
	endClock = clock(); // record end time

	runClock = endClock - startClock;
	cout << "double[400] total clock cycles: " << runClock << endl;

	startClock = clock(); // record start time
	// allocate array and save pointer in arr 10,000 times
	for (int i = 0; i < 10000; i++) {
		arr = new double[800];
	}
	endClock = clock(); // record end time

	runClock = endClock - startClock;
	cout << "double[800] total clock cycles: " << runClock << endl;


	delete[] arr; // free memory pointed to by arr
	return 0;
}