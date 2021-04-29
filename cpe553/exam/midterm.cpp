/*
	Author: James Lawrence
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


/*

***********************************************************************************************************************************************************

																		SECTION 1

***********************************************************************************************************************************************************

*/

/*
	A

	The scope of int val in get_val() does not extend outside the function get_val().
	When print_val() tries to print val, it prints the "global" static int val which is 0, rather than the user defined val in get_val().
*/
// -------------------------------------------------------------------------------------------------------------------------------------------------
/*
//	B

	The funciton f() is not initialized before it is called in main().
	To fix, we need to write void f() "above" main().

	void f() {
		cout << "hello\n";
	}

	int main() {
		f();
		return 0;
	}
*/

// -------------------------------------------------------------------------------------------------------------------------------------------------

/*
//	C

	The object a1 should use the default constructor, which accepts no args.
	Therefore, a1 should be instantiated without the () operator.

	class A {
	public:
		A() { cout << "constructor"; }
		void f() { cout << "f"; }
	};

	int main() {
		A a1;
		a1.f();
		return 0;
	}
*/

// -------------------------------------------------------------------------------------------------------------------------------------------------

/*
//	D

	I think this has something to do with the child/parent constructor clashing but I unfortunately cannot figure this one out.

	class A {
	public:
		A(int x) {}
	};

	class B : public A {
	public:
		B(int x) {}
	};
		
	void f() {
		A a(5);
		B b(2);
	}

*/

// -------------------------------------------------------------------------------------------------------------------------------------------------

/*
//	E

	The value s is never initialized, so the returned value is garbage. Also i is decremented so i should be added to s.
	Also the decrement should stop at 0 to end the loop because i is unsigned.

	int32_t sum(uint32_t n) {
		uint32_t s = 0;
		for (uint32_t i = n; i > 0; --i) {
			s += i;
		}
		return s;
	}

	int main(){
		cout << sum(5);
	}
*/

// -------------------------------------------------------------------------------------------------------------------------------------------------

/*
//	F
	
	The statement "new int(3)" makes a pointer to some integer in memory. The statement "int a" expects to be assigned an integer value.
	To fix, specify that a is a pointer to an integer (int* a) and return that pointer a (return a).

int* f() {
	int* a = new int(3);
	return a;
}

int main() {
	cout << f() << endl;
}
*/

// -------------------------------------------------------------------------------------------------------------------------------------------------

/*
//	G

	Compiler does not want unused variable and there is no way to use a const b that is uninitialized.
	Need to initialize b with a value if it is going to be const.

void f() {
	int a = 2;
	const int b = 0;
	int* p = &a;
	const int* q = &a;
}

int main() {
	f();
}
*/

// -------------------------------------------------------------------------------------------------------------------------------------------------

/*
//	H
	
	Cannot assign constant "b" a reference to a non-constant "a", otherwise if "a" changes then "b" would have to change.
	Also cannot assign different value to a constant "b."
	Based on "a" being non-constant and "b" being assigned a different value, 
	it seems that the appropriate fix is removing "const" from the initialization of "b."

void f() {
	int a = 5;
	int& b = a;
	a = 2;
	b = 3;
}

int main() {
	f();
}
*/

// -------------------------------------------------------------------------------------------------------------------------------------------------

/*
//	I

	While loop "s" does not agree in type to "char* s" , so while loop "s" needs to be "*s" to agree in type.
	Also "char* s" cannot point at a constant "msg[]" unless "char* s" is also constant.

void f() {
	const char msg[] = "CPE553!";
	const char* s = msg;

	while (*s != '\0')
		cout << s++;
	cout << endl;
}

int main() {
	f();
}
*/

// -------------------------------------------------------------------------------------------------------------------------------------------------

/*
//	J

	The child class "B" has both "g()" and inherits "f()."
	If we tried to call p->g() of "A* p" then we can only use "f()" , because "g()" only exists in the child class "B."
	To fix, we can use "B* p" to call both p->f() inherited from "A" and p-> within "B."
	This uses the inheritance, rather than adding a void f() to "A."

struct A {
	virtual void f() {}
};

struct B : public A {
	virtual void g() {}
};

void f() {
	B b1;
	A a1;
	B* p = &b1;
	p->f();
	p->g();
}

int main() {
	f();
}
*/


/*

***********************************************************************************************************************************************************

																		SECTION 2

***********************************************************************************************************************************************************

*/

/*

	// A

	The "&" symbol has different meaning in the different contexts used.
	The line "int& x" is referring to the MEMORY LOCATION of "x," which is unchanged in mystery() when the VALUE of "x" is reassigned to "t."

	To cause the 'expected failure' we need to change "int& x" to "int x" which is changing the private "x" from the MEMORY LOCATION of "x" to the VALUE of "x."
	Then, mystery() 'successfully fails' to change the VALUE of "x" to "t" because we hold the value of "int x" constant with the function signature "void mystery(int& t) const."

class A {
private:
	int& x; // "&" means memory location of x
public:
	A(int& x) : x(x) {} // "&" means reference the value of x
	
	void mystery(int& t) const { // "&" means reference the value of t
		x = t;
	}

	friend ostream& operator<<(ostream& os, const A& rhs) {
		return os << rhs.x;
	}
};

int main(int argc, char *argv[]) {
	int i = 5, j = 3;
	A a(i);
	a.mystery(j);

	// What does this print?
	// The answer to this will help you answer this question.
	cout << a << endl;
	
	return 0;
}

*/

/*

	// B

	Data encapsulation is the act of hiding private data members to a class from the user. Data encapsulation is important because the user may break a
	system if a data member is modified accidentally/maliciously. Arguably worse, without data encapsulation a user may accidentally modify a data member
	without causing a breaking change and then go on to receive unknowingly faulty end results from a system. Further, data encapsulation is important in its 
	used for hiding sensitive/confidential information from the end user.

	A scenario in which a public data member (not hidden from the user) holds passwords poses a security risk. The user has the ability to see/change passwords,
	which should be kept confidential.
*/

/*

	// C

	When dealing with dynamic memory in a class:

	- Destructor should be used to free memory tied-up in a potentially large / expensive (in terms of memory) object. This keeps the program from potentially running
	out of allocated memory.

	- Copy Constructor should be used to provide a simple way for the user to create an identiacal object of some intended class.

	- Copy Assignment Operator should be used as a simiple way for users to assign the contents of one object to another object of the same type.

*/

/*

***********************************************************************************************************************************************************

																		SECTION 3

***********************************************************************************************************************************************************

*/

// A

// Part 1: Implement the classes

class Shape3D {
public:
	virtual double surfaceArea() const =0;
};

class Sphere : public Shape3D {
private:
	double radius;

public:
	Sphere(double _radius) : radius(_radius) {}

	double surfaceArea() const override {
		return 4.0*M_PI*radius*radius; // 4 * pi * r^2
	}
};

class Cube : public Shape3D {
private:
	double sideLength;

public:
	Cube(double _sideLength) : sideLength(_sideLength) {}

	double surfaceArea() const override {
		return 6.0*sideLength*sideLength; // 6 * a^2
	}
};

// Part 2: Implement the TODOs
int main() {
	const Sphere s(1.0);
	cout << s.surfaceArea() << '\n';

	const Cube c(2.0);
	cout << c.surfaceArea() << '\n';

	vector<Shape3D*> shapes;
	// TODO: Add 1 sphere of radius 1.0 and 1 cube of side length 2.0
	// to the vector using the "new" operator
	shapes.push_back( new Sphere(1.0) );
	shapes.push_back( new Cube(2.0) );

	// TODO: Print out the surface areas of every object in the list,
	// separated by newlines. You MUST use polymorphism here; failure
	// to do so will result in no points for this item
	for (int i = 0; i < shapes.size(); i++) {
		cout << shapes[i]->surfaceArea() << endl;
	}

	// TODO: delete all the objects in the list
	for (int i = 0; i < shapes.size(); i++) {
		delete shapes[i];
	}
}


// B

class Matrix {
private:
	int rows, cols;
	double element;
	double* matrix;

public:
	Matrix(int _x, int _y, double _element) : rows(_x), cols(_y), element(_element) {
		matrix = new double[rows*cols];

		for (int i = 0; i < rows*cols; i++) {
			matrix[i] = element;
		}
	}

	~Matrix() {
		delete [] matrix;
	}

	void set(int x, int y, double value) {
		matrix[y * rows + x] = value;
	}

	friend double* operator +(Matrix left, Matrix right) {
/*
		return new Matrix top is left bottom is right
*/
	}

	friend void operator =(Matrix left, Matrix right) {
		return new Matrix(right.rows, right.cols, -1.0 * right.element)
	}

	double* operator -(Matrix left, Matrix right) {

	}

	static double* ident(int x) {
		return new Matrix(x, x, 0.0);
	}
};

int main() {
	// 5 row x 4 col, all elements = 2.0
	const Matrix m1(5, 4, 2.0);

	// set element in row 1, column 2 = 2.5
	m1.set(1, 2, 2.5);

	const Matrix m2(5, 4, 3.0); // 3 row x 4 col, all elements = 3.0
	m2.set(2, 2, -1.2); // set element in row 2, column 2 = -1.2

	const Matrix m3 = m1 + m2; // use a friend to add the two matrices
	const Matrix m4 = -m1; // use a friend to set m4 to the negative of m1
	const Matrix m5 = m1 - m2; // use a member operator

	// using the member style (not friend) define operator+ to do
	// nothing (just return the same value)
	const Matrix m6 = +m2; // m6 should be an exact copy of m2!

	// 4x4 identity matrix, all 0 except for 1s on the main diagonal
	// 1 0 0 0
	// 0 1 0 0
	// 0 0 1 0
	// 0 0 0 1
	const Matrix m4 = Matrix::ident(4);

	// support printing matrix using operator <<
	// output should be in the format like shown above with the 4x4
	cout << m3 << '\n' << m4 << '\n';
}