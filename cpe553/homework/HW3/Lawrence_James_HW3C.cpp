/*
	Author: James Lawrence
	cite: Brittany DiFede
*/

#include <iostream>
#include <string>

using namespace std;


class Body {

private:
	string name;
	float mass, x, y, z, radius;

public:
	Body(string name, float mass, float x, float y, float z, float radius) : 
		name(name), mass(mass), x(x), y(y), z(z), radius(radius) {}

	friend ostream& operator <<(ostream& s, Body& planet) {
		return s << planet.name << " " << planet.mass << " " << planet.x << " " << planet.y << " " << planet.z << " " << planet.radius;
	}

};

int main() {
	//         name      mass(kg) x y z  radius (m)
	Body earth("earth", 5.972e24, 0,0,0, 6.371e6);
	Body moon("moon",   7.34767309e22, 384.400e6,0,0,  1.737e6);
	cout << earth << '\n';
	cout << moon << '\n';
}