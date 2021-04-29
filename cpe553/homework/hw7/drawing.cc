/*
	Author: James Lawrence
	Cite: Brittany DiFede
*/

#include "drawing.hh"

using namespace std;
using namespace shapes;

Drawing::Drawing() {}

Drawing::~Drawing() {
    for (auto s : myShapes)
        delete [] s;
    // delete myShapes;
}

void Drawing::add(Shape* s) {
    myShapes.push_back(s);
}

void Drawing::print(string name) {
    for (auto s : myShapes)
        s->print(name);
}