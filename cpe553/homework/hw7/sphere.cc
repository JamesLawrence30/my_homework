/*
	Author: James Lawrence
	Cite: Brittany DiFede
*/

#include "sphere.hh"

using namespace shapes;
using namespace std;

Sphere::Sphere(int x, int y, int z, int r, int numfacets) : Shape(x, y, z), r(r), numfacets(numfacets) {}

void Sphere::print(string name) {
    ofstream sphereFile;
    sphereFile.open(name, ofstream::out | ofstream::app); // create or append
    sphereFile << "solid OpenSCAD_Model" << endl;
    sphereFile << "sphere..." << endl;
    sphereFile << "endsolid OpenSCAD_Model" << endl;
    sphereFile.close();
}