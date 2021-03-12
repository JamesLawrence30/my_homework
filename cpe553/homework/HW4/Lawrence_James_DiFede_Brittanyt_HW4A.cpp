/*
	Author: James Lawrence & Brittany DiFede (partners)
*/

#include <time.h>
#include <iostream>
#include <cmath>

using namespace std;

class Vec3d {
private:
    double x, y, z;

public:

    Vec3d(double x, double y, double z) : x(x), y(y), z(z) {}
   
    Vec3d(double x) : x(x), y(0.0), z(0.0) {}
   
    Vec3d(double x, double y) : x(x), y(y), z(0.0) {}

    Vec3d() : x(0.0), y(0.0), z(0.0) {}
    
    friend Vec3d operator +(const Vec3d& left, const Vec3d& right) {
        return Vec3d(left.x + right.x, left.y + right.y, left.z + right.z);
    }

    friend Vec3d operator -(const Vec3d& left, const Vec3d& right) {
        return Vec3d(left.x - right.x, left.y - right.y, left.z - right.z);
    }

    friend Vec3d operator -(const Vec3d& vec) {
        return Vec3d(-vec.x, -vec.y, -vec.z);
    }

    friend double dot(const Vec3d& left, const Vec3d& right) {
        return left.x*right.x + left.y*right.y + left.z*right.z;
    }
    
    double dot(const Vec3d& vec) const {
        return this->x*vec.x + this->y*vec.y + this->z*vec.z;
    }

    static double dot(const Vec3d& a, const Vec3d& b) {
        return a.x*b.x + a.y*b.y + a.z*b.z;
    }
    
    double mag() const {
        return sqrt( pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) );
    }

    double magSq() const {
        return pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2);
    }

    double dist(const Vec3d& vec) const {
        return sqrt( pow(this->x - vec.x, 2) + pow(this->y - vec.y, 2) + pow(this->z - vec.z, 2) );
    }

    friend ostream& operator <<(ostream& s, Vec3d vec) {
        return s << '(' << vec.x << "," << vec.y << ',' << vec.z << ')';
    }
};

int main() {
	// Main() Section 1
	const Vec3d a(1.0,2.5,3.5); // double precision!
	const Vec3d b(2.0);         //(2,0,0)
	const Vec3d c(2.0,3.5);     //(2,3.5,0)
	const Vec3d d;              //(0,0,0)

	// Main() Section 2
	const Vec3d e = a + d;  // use friend
	const Vec3d f = c - b;	// use friend
	const Vec3d g = -e;     // use friend
	
	// Main() Section 3	
	double r = dot(e, f); // regular function  e.x*f.x + e.y*f.y + e.z*f.z  (friend)
	double s = e.dot(f); // method
    double t = Vec3d::dot(e,f); // static function

	// Main() Section 4	
	double x = e.mag(); // square root of sum of square
	double y = e.magSq(); // sum of square
	double z = e.dist(f); // sqrt or sum of square of diff

	// Main() Section 5	
	cout << "a: " << a << '\n';
	cout << "b: " << b << '\n';
	cout << "c: " << c << '\n';
	cout << "d: " << d << '\n';
	cout << "e: " << e << '\n';
	cout << "f: " << f << '\n';
	cout << "g: " << g << '\n';
	cout << "r: " << r << '\n';
	cout << "s: " << s << '\n';
	cout << "x: " << x << '\n';
	cout << "y: " << y << '\n';
	cout << "z: " << z << '\n';
}	