/*
	Author: James Lawrence
	cite: N/A
*/

#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;


long double getSideLength(long double& r, int& sideCount) {

	// polygon side length = 2 * inscribed circle radius * tan(pi/number of sides)
	return 2.0 * r * tan(3.14159265 / sideCount);
}

void circle(int& n, long double& r, long double sideLength, int sideCount) { // pass by reference so we can manipulate n and radius
	n += 1;

	// circumscribed circle radius = inscribed polygon side length / ( 2*sin(pi / inscribed polygon side count) )
	r = sideLength / (2 * sin(3.14159265/sideCount));
	
	if (n == 10 || n == 100 || n == 1000 || n == 10000 || n == 100000 || n == 1000000 || n == 10000000)
		cout << "n = " << n << "  Radius = " << r << endl;
}

void triangle(int& n, long double& r) {
	int sides = 3;
	n += sides;

	long double sideLength = getSideLength(r, sides);

	circle(n, r, sideLength, sides); //angle in radians
}

void square(int& n, long double& r) {
	int sides = 4;
	n += sides;

	long double sideLength = getSideLength(r, sides);

	circle(n, r, sideLength, sides);
}

void pentagon(int& n, long double& r) {
	int sides = 5;
	n += sides;

	long double sideLength = getSideLength(r, sides);

	circle(n, r, sideLength, 5);
}


int main() {

	int n = 1;
	long double radius = 1.0;
	while (n <= 1000000) { // starting with circle of radius = 1
		
		triangle(n, radius);

		square(n, radius);
		
		pentagon(n, radius);
	}
	
	
	return 1;
}