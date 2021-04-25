/*
	Authors (group): James Lawrence & Brittany DiFede
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class Shape {
public:
  virtual void draw(ostream& s) = 0;
  virtual ~Shape() {} // virtual destructor. must be written for each child
};

class Rect : public Shape {
private:
	float moveX, moveY, lineX, lineY;
public:
	Rect(float _moveX, float _moveY, float _lineX, float _lineY) : 
		moveX(_moveX), moveY(_moveY), lineX(_lineX), lineY(_lineY) {}

	~Rect() {
		cout << "destroyed Rect" << endl;
	}

 void draw(ostream& s) {
 	s << "% Rectangle" << endl;
 	s << moveX << " " << moveY << " moveto" << endl; // 100 150 moveto
 	s << lineX << " " << moveY << " lineto" << endl; // 200 150 lineto
 	s << lineX << " " << lineY << " lineto" << endl; // 200 50 lineto
 	s << moveX << " " << lineY << " lineto" << endl; // 100 50 lineto
 	s << "closepath stroke" << endl << endl;
 }
};

class FilledRect : public Shape {
private:
	float moveX, moveY, lineX, lineY;
public:
	FilledRect(float _moveX, float _moveY, float _lineX, float _lineY) : 
		moveX(_moveX), moveY(_moveY), lineX(_lineX), lineY(_lineY) {}

	~FilledRect() {
		cout << "destroyed FilledRect" << endl;
	}

 void draw(ostream& s) {
 	s << "% Filled Rectangle" << endl;
 	s << moveX << " " << moveY << " moveto" << endl;
 	s << lineX << " " << moveY << " lineto" << endl;
 	s << lineX << " " << lineY << " lineto" << endl;
 	s << moveX << " " << lineY << " lineto" << endl;
 	s << "closepath fill" << endl << endl;
 }
};

class Circle : public Shape {
private:
	float x, y, r;
public:
	Circle(float _x, float _y, float _r) : x(_x), y(_y), r(_r) {}

	~Circle() {
		cout << "destroyed Circle" << endl;
	}

 void draw(ostream& s) {
 	s << "% Circle" << endl;
 	s << x << " " << y << " " << r << " 0 360 arc stroke" << endl << endl;
 }
};

class FilledCircle : public Shape {
private:
	float x, y, r;
public:
	FilledCircle(float _x, float _y, float _r) : x(_x), y(_y), r(_r) {}

	~FilledCircle() {
		cout << "destroyed FilledCircle" << endl;
	}

 void draw(ostream& s) {
 	s << "% Filled Circle" << endl;
 	s << x << " " << y << " " << r << " 0 360 arc fill" << endl << endl;
 }
};

class Line : public Shape {
private:
	float moveX, moveY, lineX, lineY;
public:
	Line(float _moveX, float _moveY, float _lineX, float _lineY) :
		moveX(_moveX), moveY(_moveY), lineX(_lineX), lineY(_lineY) {}

	~Line() {
		cout << "destroyed Line" << endl;
	}

 void draw(ostream& s) {
 	s << "% Line" << endl;
 	s << moveX << " " << moveY << " moveto " << lineX << " " << lineY << " lineto stroke" << endl << endl;
 }
};

class Polygon : public Shape {
private:
	float moveX, moveY, sideLen, sideCount;
public:
	Polygon(float _moveX, float _moveY, float _sideLen, float _sideCount) : 
		moveX(_moveX), moveY(_moveY), sideLen(_sideLen), sideCount(_sideCount) {}

	~Polygon() {
		cout << "destroyed Polygon" << endl;
	}

 void draw(ostream& s) {
	s << "% Polygon";

	if(sideCount == 6) {
		s << " - Hexagon" << endl;
		s << moveX << " " << moveY << " moveto" << endl; // point 1
		s << moveX+sideLen << " " << moveY << " lineto" << endl; // point 2
		s << moveX+sideLen+(sideLen/sqrt(2)) << " " << moveY+(sideLen/sqrt(2)) << " lineto" << endl; // point 3
		s << moveX+sideLen << " " << moveY+(sideLen/sqrt(2))+(sideLen/sqrt(2)) << " lineto" << endl; // point 4
		s << moveX << " " << moveY+(sideLen/sqrt(2))+(sideLen/sqrt(2)) << " lineto" << endl; // point 5
		s << moveX-(sideLen/sqrt(2)) << " " << moveY+(sideLen/sqrt(2)) << " lineto" << endl; // point 6
		s << "closepath stroke" << endl << endl; // back to point 1
	} 
 }
};

class Color : public Shape {
private:
	float r, g, b;
public:
	Color(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}

	~Color() {
		cout << "destroyed Color" << endl;
	}

  void draw(ostream& s) {
  	s << "% set RGB" << endl;
  	s << r << " " << g << " " << b << " setrgbcolor" << endl << endl;
  }
};


class Drawing {
private:
	ofstream f;
	vector<Shape*> shapes;
public:
	Drawing(string filename) : f(filename.c_str()), shapes() {
	}

	~Drawing() { // write destructor
		for (int i = 0; i < shapes.size(); i++) {
			delete shapes[i]; // polymorphic destructor through base Shape class to delete child shapes
		}
	}

	void add( Shape* s ) {
    shapes.push_back(s);
	}

	void setrgb(float r, float g, float b) {
		Shape* c = new Color(r,g,b);
    shapes.push_back(c);
	}

	void draw() {
		for (int i = 0; i < shapes.size(); i++)
			shapes[i]->draw(f);
	}
};

void printIt(Drawing& d) {
	d.draw();
}

int main() {
	Drawing d("test2.ps");
	d.setrgb(1,0,0); // set drawing color to be bright red:  1 0 0 setrgbcolor
	//d.setrgb should be equivalent to d.add(new RGB(...)) You have to make another object
	d.add(new FilledRect(100.0, 150.0, 200.0, 50)); // x y moveto x y lineto ... fill
	d.add(new Rect(100.0, 150.0, 200.0, 50));       // x y moveto x y lineto ... stroke
	for (int x = 0; x < 600; x += 100)
		d.add(new FilledCircle(x,200,50.0)); // x y r 0 360 arc fill
	d.setrgb(0,1,0); // the rest are green

	d.add(new Circle(0,0, 100)); // 0 0 100 0 360 stroke
	d.add(new Line(400,500, 600,550));
	d.add(new Polygon(200,200, 50, 6)); //OPTIONAL+40%	
  printIt(d);
}
