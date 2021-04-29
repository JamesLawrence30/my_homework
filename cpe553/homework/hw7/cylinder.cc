/*
	Author: James Lawrence
	Cite: Brittany DiFede
    Cite: https://github.com/007Robin/STL-File-CAD
*/

#include "cylinder.hh"

using namespace std;
using namespace shapes;

Cylinder::Cylinder(int x, int y, int z, int r, int h, int f) : Shape(x, y, z), r(r), h(h), f(f) {}

// Citation: https://github.com/007Robin/STL-File-CAD
void Cylinder::print(string name) {
    ofstream cylinderFile;
    cylinderFile.open(name, ofstream::out | ofstream::app); // create or append
    cylinderFile << "solid OpenSCAD_Model" << endl;
    
    Shape v1(x + r*cos(0), y + r*sin(0), h + z);
    Shape v2(x, y, h + z);
    Shape v3;
    Shape v1_d = v1 - Shape(0,0,h);
    Shape v2_d = v2 - Shape(0,0,h);
    Shape v3_d;
    for(int i = 0; i < f; ++i) {				
        v3 = Shape (x + r*cos(2*M_PI/f*(1+i)), y + r*sin(2*M_PI/f*(1+i)), h + z);
        //up circle				
        Shape f1 = get_Normal(v1, v3, v2);
        cylinderFile << ' ' << "facet normal " << f1 << endl;
        cylinderFile << ' ' << ' ' << "outer loop" << endl;
        cylinderFile << ' ' << ' ' << ' ' << "vertex " << v1 << endl;
        cylinderFile << ' ' << ' ' << ' ' << "vertex " << v3 << endl;
        cylinderFile << ' ' << ' ' << ' ' << "vertex " << v2 << endl;
        cylinderFile << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
        //down circle
        v3_d = v3 - Shape(0,0,h);
        Shape f2 = get_Normal(v1_d, v2_d, v3_d);
        cylinderFile << ' ' << "facet normal " << f2 << endl;
        cylinderFile << ' ' << ' ' << "outer loop" << endl;
        cylinderFile << ' ' << ' ' << ' ' << "vertex " << v1_d << endl;
        cylinderFile << ' ' << ' ' << ' ' << "vertex " << v2_d << endl;
        cylinderFile << ' ' << ' ' << ' ' << "vertex " << v3_d << endl;
        cylinderFile << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
        //v1 v1_d v3_d
        Shape f3 = get_Normal(v1, v1_d, v3);
        cylinderFile << ' ' << "facet normal " << f3 << endl;
        cylinderFile << ' ' << ' ' << "outer loop" << endl;
        cylinderFile << ' ' << ' ' << ' ' << "vertex " << v1 << endl;
        cylinderFile << ' ' << ' ' << ' ' << "vertex " << v1_d << endl;
        cylinderFile << ' ' << ' ' << ' ' << "vertex " << v3_d << endl;
        cylinderFile << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
        //v3_d v3 v1
        Shape f4 = get_Normal(v1_d, v3, v3_d);
        cylinderFile << ' ' << "facet normal " << f4 << endl;
        cylinderFile << ' ' << ' ' << "outer loop" << endl;
        cylinderFile << ' ' << ' ' << ' ' << "vertex " << v3_d << endl;
        cylinderFile << ' ' << ' ' << ' ' << "vertex " << v3 << endl;
        cylinderFile << ' ' << ' ' << ' ' << "vertex " << v1 << endl;
        cylinderFile << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;

        v1 = v3;
        v1_d = v3_d;
    }
    
    cylinderFile << "endsolid OpenSCAD_Model" << endl;
    cylinderFile.close();
}