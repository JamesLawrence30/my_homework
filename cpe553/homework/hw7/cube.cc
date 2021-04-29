/*
	Author: James Lawrence
	Cite: Brittany DiFede
*/

#include "cube.hh"

using namespace std;
using namespace shapes;

Cube::Cube(int x, int y, int z, int s) : Shape(x, y, z), s(s) {}

void Cube::print(string name) {
    ofstream cubeFile;
    cubeFile.open(name, ofstream::out | ofstream::app); // create or append
    cubeFile << "solid OpenSCAD_Model" << endl;



    cubeFile << "facet normal -0 0 1\n  outer loop\n";
    cubeFile << "    vertex " << (x) << ' ' << (y + s) << ' ' << (z + s) << '\n'; // 7
    cubeFile << "    vertex " << (x + s) << ' ' << (y) << ' ' << (z + s) << '\n'; // 6
    cubeFile << "    vertex " << (x + s) << ' ' << (y + s) << ' ' << (z + s) << '\n'; // 8
    cubeFile << "  endloop\nendfacet\n";

    cubeFile << "facet normal 0 0 1\n  outer loop\n";
    cubeFile << "    vertex " << (x + s) << ' ' << (y) << ' ' << (z + s) << '\n'; // 6
    cubeFile << "    vertex " << (x) << ' ' << (y + s) << ' ' << (z + s) << '\n'; // 7
    cubeFile << "    vertex " << (x) << ' ' << (y) << ' ' << (z + s) << '\n'; // 5
    cubeFile << "  endloop\nendfacet\n";



    cubeFile << "facet normal 0 0 -1\n  outer loop\n";
    cubeFile << "    vertex " << (x) << ' ' << (y) << ' ' << (z) << '\n'; // 1
    cubeFile << "    vertex " << (x + s) << ' ' << (y + s) << ' ' << (z) << '\n'; // 3
    cubeFile << "    vertex " << (x + s) << ' ' << (y) << ' ' << (z) << '\n'; // 4
    cubeFile << "  endloop\nendfacet\n";

    cubeFile << "facet normal -0 0 -1\n  outer loop\n";
    cubeFile << "    vertex " << (x + s) << ' ' << (y + s) << ' ' << (z) << '\n'; // 3
    cubeFile << "    vertex " << (x) << ' ' << (y) << ' ' << (z) << '\n'; // 1
    cubeFile << "    vertex " << (x) << ' ' << (y + s) << ' ' << (z) << '\n'; // 2
    cubeFile << "  endloop\nendfacet\n";



    cubeFile << "facet normal 0 -1 0\n  outer loop\n";
    cubeFile << "    vertex " << (x) << ' ' << (y) << ' ' << (z) << '\n'; // 1
    cubeFile << "    vertex " << (x + s) << ' ' << (y) << ' ' << (z + s) << '\n'; // 6
    cubeFile << "    vertex " << (x) << ' ' << (y) << ' ' << (z + s) << '\n'; // 5
    cubeFile << "  endloop\nendfacet\n";

    cubeFile << "facet normal 0 -1 -0\n  outer loop\n";
    cubeFile << "    vertex " << (x + s) << ' ' << (y) << ' ' << (z + s) << '\n'; // 6
    cubeFile << "    vertex " << (x) << ' ' << (y) << ' ' << (z) << '\n'; // 1
    cubeFile << "    vertex " << (x + s) << ' ' << (y) << ' ' << (z) << '\n'; // 4
    cubeFile << "  endloop\nendfacet\n";



    cubeFile << "facet normal 1 -0 0\n  outer loop\n";
    cubeFile << "    vertex " << (x + s) << ' ' << (y) << ' ' << (z + s) << '\n'; // 6
    cubeFile << "    vertex " << (x + s) << ' ' << (y + s) << ' ' << (z) << '\n'; // 3
    cubeFile << "    vertex " << (x + s) << ' ' << (y + s) << ' ' << (z + s) << '\n'; // 8
    cubeFile << "  endloop\nendfacet\n";

    cubeFile << "facet normal 1 0 0\n  outer loop\n";
    cubeFile << "    vertex " << (x + s) << ' ' << (y + s) << ' ' << (z) << '\n'; // 3
    cubeFile << "    vertex " << (x + s) << ' ' << (y) << ' ' << (z + s) << '\n'; // 6
    cubeFile << "    vertex " << (x + s) << ' ' << (y) << ' ' << (z) << '\n'; // 4
    cubeFile << "  endloop\nendfacet\n";



    cubeFile << "facet normal 0 1 -0\n  outer loop\n";
    cubeFile << "    vertex " << (x + s) << ' ' << (y + s) << ' ' << (z) << '\n'; // 3
    cubeFile << "    vertex " << (x) << ' ' << (y + s) << ' ' << (z + s) << '\n'; // 7
    cubeFile << "    vertex " << (x + s) << ' ' << (y + s) << ' ' << (z + s) << '\n'; // 8
    cubeFile << "  endloop\nendfacet\n";

    cubeFile << "facet normal 0 1 0\n  outer loop\n";
    cubeFile << "    vertex " << (x) << ' ' << (y + s) << ' ' << (z + s) << '\n'; // 7
    cubeFile << "    vertex " << (x + s) << ' ' << (y + s) << ' ' << (z) << '\n'; // 3
    cubeFile << "    vertex " << (x) << ' ' << (y + s) << ' ' << (z) << '\n'; // 2
    cubeFile << "  endloop\nendfacet\n";



    cubeFile << "facet normal -1 0 0\n  outer loop\n";
    cubeFile << "    vertex " << (x) << ' ' << (y) << ' ' << (z) << '\n'; // 1
    cubeFile << "    vertex " << (x) << ' ' << (y + s) << ' ' << (z + s) << '\n'; // 7
    cubeFile << "    vertex " << (x) << ' ' << (y + s) << ' ' << (z) << '\n'; // 2
    cubeFile << "  endloop\nendfacet\n";

    cubeFile << "facet normal -1 -0 0\n  outer loop\n";
    cubeFile << "    vertex " << (x) << ' ' << (y + s) << ' ' << (z + s) << '\n'; // 7
    cubeFile << "    vertex " << (x) << ' ' << (y) << ' ' << (z) << '\n'; // 1
    cubeFile << "    vertex " << (x) << ' ' << (y) << ' ' << (z + s) << '\n'; // 5
    cubeFile << "  endloop\nendfacet\n";


    cubeFile << "endsolid OpenSCAD_Model" << endl;
    cubeFile.close();


}








//     // ======START Front face======
//     // Triangle = Top left, Bottom right, Top right
//     cubeFile << "facet normal -0 0 1\n  outer loop\n";
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "  endloop\nendfacet\n";

//     // Triangle = Bottom right, Top left, Bottom left
//     cubeFile << "facet normal 0 0 1\n  outer loop\n";
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "  endloop\nendfacet\n";
//     // ======END Front face======


//     // ======START Left face======
//     // Triangle = Top left, Bottom right, Top right
//     cubeFile << "facet normal -1 0 0\n outer loop\n";
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "  endloop\nendfacet\n";

//     // Triangle = Bottom right, Top left, Bottom left
//     cubeFile << "facet normal -1 0 0\n  outer loop\n";
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "  endloop\nendfacet\n";
//     // ======END Left face======


//     // ======START Back face======
//     // Triangle = Top left, Bottom right, Top right
//     cubeFile << "facet normal 0 0 -1\n outer loop\n";
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "  endloop\nendfacet\n";

//     // Triangle = Bottom right, Top left, Bottom left
//     cubeFile << "facet normal 0 0 -1\n  outer loop\n";
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "  endloop\nendfacet\n";
//     // ======END Back face======


//     // ======START Right face======
//     // Triangle = Top left, Bottom right, Top right
//     cubeFile << "facet normal 1 0 0\n outer loop\n";
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "  endloop\nendfacet\n";

//     // Triangle = Bottom right, Top left, Bottom left
//     cubeFile << "facet normal 1 0 0\n  outer loop\n";
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "  endloop\nendfacet\n";
//     // ======END Back face======


//     // ======START Top face======
//     // Triangle = Top left, Bottom right, Top right
//     cubeFile << "facet normal 0 1 0\n outer loop\n";
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "  endloop\nendfacet\n";

//     // Triangle = Bottom right, Top left, Bottom left
//     cubeFile << "facet normal 0 1 0\n  outer loop\n";
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "  endloop\nendfacet\n";
//     // ======END Top face======


//     // ======START Bottom face======
//     // Triangle = Top left, Bottom right, Top right
//     cubeFile << "facet normal 0 -1 0\n outer loop\n";
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "  endloop\nendfacet\n";

//     // Triangle = Bottom right, Top left, Bottom left
//     cubeFile << "facet normal 0 -1 0\n  outer loop\n";
//     cubeFile << "    vertex " << (x + s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y + s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "    vertex " << (x - s/2) << ' ' << (y - s/2) << ' ' << (z + s/2) << '\n';
//     cubeFile << "  endloop\nendfacet\n";
//     // ======END Top face======

//     cubeFile << "endsolid OpenSCAD_Model" << endl;
//     cubeFile.close();
// }