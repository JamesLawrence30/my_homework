/*
	Author: James Lawrence
	Cite: Brittany DiFede
*/

#pragma once

#include "shape.hh"
#include <string>
#include <fstream>
#include <iostream>

namespace shapes {
    class Sphere : public Shape{
    private:
        int r, numfacets;

    public:
        Sphere(int x, int y, int z, int r, int numfacets);
        void print(std::string fileName);
    };
};