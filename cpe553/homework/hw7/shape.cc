/*
	Author: James Lawrence
	Cite: Brittany DiFede
*/

#include "shape.hh"
#include <ostream>

using namespace std;
using namespace shapes;

Shape::Shape() : x(0), y(0), z(0) {}

Shape::Shape(int x, int y, int z) : x(x), y(y), z(z) {}

Shape Shape::get_Normal(const Shape& p1, const Shape& p2, const Shape& p3 ){  
    double a = ( (p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y) );  
    double b = ( (p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z) );  
    double c = ( (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) );  
    return Shape(a,b,c);  
}

Shape shapes::operator -(const Shape& v1, const Shape& v2){
	Shape ans;
	ans.x = v1.x - v2.x;
	ans.y = v1.y - v2.y;
	ans.z = v1.z - v2.z;
	return ans;
}

ostream& shapes::operator <<(ostream& s, const Shape& v) {
	s << v.x << " " << v.y << " " << v.z;
	return s;
}