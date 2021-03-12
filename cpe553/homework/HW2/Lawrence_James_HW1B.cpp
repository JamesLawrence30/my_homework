/*
	Author: James Lawrence
	cite: N/A
*/

#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

void circle(int& n, long double& r, long double polygonSide, double vertexAngle) { // pass by reference so we can manipulate n and radius
	n += 1;

	// circumscribed circle radius = inscribed polygon side / ( 2*sin(vertex angle / 2) )
	r = polygonSide / (2 * sin(vertexAngle/2));
	
	if (n == 10 || n == 100 || n == 1000 || n == 10000 || n == 100000 || n == 1000000 || n == 10000000)
		cout << "n = " << n << "  Radius = " << r << endl;
}

void triangle(int& n, long double& r) {
	n += 3;
/*
	// circumscribed triangle area = (base * height) / 2
	// ...circumscribed triangle area = ((2*(height/sqrt(3))) * (3 * inscribed circle radius)) / 2
	long double height = 3*r;
	long double base = 2*(height/sqrt(3));
	long double triangleArea = (base*height) / 2;

	// circumscribed circle radius = triangleArea / sqrt(3);
	r = triangleArea / sqrt(3);
	circle(n, r, base, 1.0472);
*/

	// circumscribed triangle area = (base * height) / 2
	// ...circumscribed triangle area = ((2*(height/sqrt(3))) * (3 * inscribed circle radius)) / 2
	long double height = 3*r;
	long double base = 2*(height/sqrt(3));

	circle(n, r, base, 1.0472); //angle in radians
}

void square(int& n, long double& r) {
	n += 4;
/*
	// circumscribed square area = base * height
	// circumscribed square area = inscribed circle diameter * inscribed circle diameter
	// ...circumscribed square area = (inscribed circle radius*2) * (inscribed circle radius*2)
	long double squareArea = pow(r*2, 2);

	// circumscribed circle diameter = inscribed square Side * sqrt(2)
	// circumscribed circle radius = circumscribed circle diameter / 2
	// ...circumscribed circle radius = ( sqrt(inscribed square area) * sqrt(2) ) / 2
	r = ( sqrt(squareArea) * sqrt(2) ) / 2;
	circle(n, r);
*/

	// circumscribed square area = base * height
	// circumscribed square area = inscribed circle diameter * inscribed circle diameter
	// ...circumscribed square area = (inscribed circle radius*2) * (inscribed circle radius*2)
	long double side = r*2;

	circle(n, r, side, 1.5708);
}

void pentagon(int& n, long double& r) {
	n += 5;

	// polygon side = 2 * inscribed circle radius * tan(pi/number of sides)
	// pentagon side = 2 * inscribed circle radius * tan(pi/5)
	long double side = 2.0 * r * tan(3.14159265 / 5.0);

	circle(n, r, side, 1.88496);
}


int main() {

	int n = 1;
	long double radius = 1.0;
	while (n <= 1000000) { // starting with circle of radius = 1
		
		triangle(n, radius);

		//square(n, radius);
		
		//pentagon(n, radius);
	}
	
	
	return 1;
}

/*
	calculate area? of triangle given a circle with radius r
	then calculate new radius of circle around the triangle
	return new circle radius
*/