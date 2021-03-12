/*
	Author: James Lawrence
	cite: N/A
*/

#include <iostream>
#include <cmath>

int main() {

	// Print Temperature (F) across top row
	std::cout << "\t";
	for (int T = 40; T >= -45; T -= 5) {
		std::cout << T << "\t";
	}
	std::cout << std::endl <<std::endl;


	float chill;
	for (int V = 5; V <= 60; V += 5) { // For each Wind (mph)
		std::cout << V << "\t";			// Start row with Wind value

		for (int T = 40; T >= -45; T -= 5) { // For each Temperature (F)

			chill = 35.74 + 0.6215*T - 35.75*pow(V,0.16) + 0.4275*T*pow(V, 0.16); // Calculate Wind chill
			std::cout << round(chill) << "\t";
		}
		std::cout << std::endl;
	}

	return 1;
}

// use nested for loops
// can use cmath library (pow, etc.), round fundtion to round off
// dont need to do colors or border

/*

use nested loop, approx 7 lines of code


for
	for
		print
	print
.
.
.

*/