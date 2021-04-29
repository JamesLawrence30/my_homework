/*
	Author: James Lawrence
	Cite: Brittany DiFede
*/

#pragma once

#include "shape.hh"
#include <fstream>
#include <iostream>

namespace shapes {
    class Cube : public Shape {
        private:
            std::ofstream f;
            int s;

        public:
            Cube(int x, int y, int z, int s);
            void print(std::string name);
    };
};