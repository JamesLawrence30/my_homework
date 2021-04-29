/*
	Author: James Lawrence
	Cite: Brittany DiFede
*/

#pragma once

#include <string>
#include <ostream>

namespace shapes {
    class Shape {
    protected:
        int x, y, z;

    public:
        Shape();
        Shape(int x, int y, int z);
        virtual void print(std::string fileName) {}
		Shape get_Normal(const Shape& p1, const Shape& p2, const Shape& p3 );
        friend Shape operator -(const Shape& v1, const Shape& v2);
        friend std::ostream& operator <<(std::ostream& s, const Shape& v);
    };
};