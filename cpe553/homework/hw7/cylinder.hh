/*
	Author: James Lawrence
	Cite: Brittany DiFede
    Cite: https://github.com/007Robin/STL-File-CAD
*/

#pragma once

#include "shape.hh"
#include <fstream>
#include <iostream>
#include <cmath>

namespace shapes {
    class Cylinder : public Shape{
        private:
        std::ofstream file;
            int r, h, f;
        
        public:
            Cylinder(int x, int y, int z, int r, int h, int f);
            void print(std::string name);
    };
};