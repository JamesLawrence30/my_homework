/*
	Author: James Lawrence
	cite: Equations used, tested from
			https://keisan.casio.com/exec/system/1223430310
			https://keisan.casio.com/exec/system/1223432608
			https://keisan.casio.com/exec/system/1223430387
			https://keisan.casio.com/exec/system/1223430310
*/

#include <iostream>
#include <cmath>

using namespace std;


long double getPolygonSideLength(long double& r, int& sideCount) {

	// polygon side length = 2 * inscribed circle radius * tan(pi/number of sides)
	return 2.0 * r * tan(3.14159265 / sideCount);
}

void circumscribeCircle(int& n, long double& r, long double sideLength, int sideCount) { // pass by reference so we can manipulate n and radius
	n += 1;

	// circumscribed circle radius = inscribed polygon side length / ( 2*sin(pi / inscribed polygon side count) )
	r = sideLength / (2 * sin(3.14159265/sideCount));
	
	if (n == 10 || n == 100 || n == 1000 || n == 10000 || n == 100000 || n == 1000000 || n == 10000000)
		cout << "n = " << n << "  Radius = " << r << endl;
}

int main() {

	int sides = 0;
	int n = 1;
	long double sideLength = 0.0;
	long double radius = 1.0;
	while (n <= 1000000) { // starting with circle of radius = 1
		
		/* Circumscribe the given polygon about a circle,
			then circumscribe a circle about the polygon
			of a given side length.
		*/

		// Triangle
		sides = 3;
		n += sides;
		sideLength = getPolygonSideLength(radius, sides);
		circumscribeCircle(n, radius, sideLength, sides);	

		// Square
		sides = 4;
		n += sides;
		sideLength = getPolygonSideLength(radius, sides);
		circumscribeCircle(n, radius, sideLength, sides);	
		
		// Pentagon
		sides = 5;
		n += sides;
		sideLength = getPolygonSideLength(radius, sides);
		circumscribeCircle(n, radius, sideLength, sides);	
	}
	
	return 1;
}

/*
	Ran out of bits in long double to hold the final
	n = 1000000 circumscribed circle.
*/