/*
	Author: James Lawrence
	Cite: Brittany DiFede
*/

#pragma once

#include "shape.hh"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

namespace shapes {
    class Drawing {
    private:
        std::vector<Shape*> myShapes;

    public:
        Drawing();
        ~Drawing();
        void print(std::string fileName);
        void add(Shape* s);
    };
};