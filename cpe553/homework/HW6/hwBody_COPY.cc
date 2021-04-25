/*
	Author: James Lawrence
	Cite: Brittany DiFede
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;


class Vec3d {
private:
	double x, y, z;

public:
	Vec3d() {}
	Vec3d(double _x, double _y) : x(_x), y(_y), z(0) {}

	friend ostream& operator <<(ostream& s, Vec3d vec) {
		return s << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	}
};

class Body {
private:
	string name;
	double mass;   // mass of the body
	double radius; // size of the body (assumes spherical)
	Vec3d pos;     // pos = (x,y,0) ignore z for now. x,y should be based on orbital radius
	Vec3d v;       // v = 0 next week we have to calculate
	Vec3d a;       // a = 0 next week we compute gravitational acceleration due to all other bodies

public:
  	Body() : name(), pos(), v(), a() {}
	
  friend ostream& operator <<(ostream& s, const Body& b) {
  	return s << b.name <<  "\t" << setw(12) << b.mass << "\t" << setw(10) << b.radius << "\t" << setw(2) << b.pos << endl;
	}

  friend istream& operator >>(istream& s, Body&  b) {

  	string garbage;
  	double diam, per, aph;
  	double t, x, y;
  	char buf[1024];

	s.getline(buf, sizeof(buf));
	istringstream line(buf);
	line >> b.name >> garbage >> b.mass >> diam >> per >> aph;
	b.radius = diam/2;

	t = rand() % (int)(2.0*M_PI + 1.0);
	x = ((per+aph)/2) * cos(t);
	y = ((per+aph)/2) * sin(t);
	b.pos = Vec3d(x,y);

	return s;
	}
};


int main() {
	ifstream solarsystem("solarsystem.dat");
	char buf[1024];
	solarsystem.getline(buf, sizeof(buf)); // throw out first line

	Body sun, mercury, venus, earth, moon;
	solarsystem >> sun >> mercury >> venus >> earth;

	// read in the name of each body
	// compute average distance of each body from sun (average of perihelion and aphelion)
	// pick t = a random number from 0 to 2*pi
	// 
	// calculate x,y = r cos t, r sin t
	// put into pos vector (x,y, 0)

	// next step (not necessary this week)
	// calculate V
	// pretend all orbits are circular
	// calculate the length of the circular path around the sun 2*pi * r
	// look up time it takes to orbit
	// convert to meters and seconds
	// v = distance around the sun / orbital period in seconds
	cout << sun << mercury << venus << earth;
}


/* NOTES:
 		print out name, mass, radius, and position.

 		For reading in the file, look at the line:
		solarsystem >> sun >> mercury >> venus >> earth;

*/