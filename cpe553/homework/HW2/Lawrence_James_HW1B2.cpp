/*
	Author: James Lawrence
	cite: N/A
*/

#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

void circle(int& n, long double& r, long double sideLength, int sideCount) { // pass by reference so we can manipulate n and radius
	n += 1;

	// circumscribed circle radius = inscribed polygon side length / ( 2*sin(pi / inscribed polygon side count) )
	r = sideLength / (2 * sin(3.14159265/sideCount));
	
	if (n == 10 || n == 100 || n == 1000 || n == 10000 || n == 100000 || n == 1000000 || n == 10000000)
		cout << "n = " << n << "  Radius = " << r << endl;
}

void triangle(int& n, long double& r) {
	n += 3;

	// circumscribed triangle area = (base * height) / 2
	// ...circumscribed triangle area = ((2*(height/sqrt(3))) * (3 * inscribed circle radius)) / 2
	long double height = 3*r;
	long double base = 2*(height/sqrt(3));

	circle(n, r, base, 3); //angle in radians
}

void square(int& n, long double& r) {
	n += 4;

	// circumscribed square area = base * height
	// circumscribed square area = inscribed circle diameter * inscribed circle diameter
	// ...circumscribed square area = (inscribed circle radius*2) * (inscribed circle radius*2)
	long double side = r*2;

	circle(n, r, side, 4);
}

void pentagon(int& n, long double& r) {
	n += 5;

	// polygon side = 2 * inscribed circle radius * tan(pi/number of sides)
	// pentagon side = 2 * inscribed circle radius * tan(pi/5)
	long double side = 2.0 * r * tan(3.14159265 / 5.0);

	circle(n, r, side, 5);
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