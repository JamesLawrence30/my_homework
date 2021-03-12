/*
	Author: James Lawrence
	Cite: Brittany DiFede
*/


/*
	Make the following main work by writing a class Complex.
	Replace this comment with your author information and cite as necessary.

	Notice that since objects are const, you will have to promise not to change them
 */
#include <iostream>

using namespace std;


class Complex {

private:
	float real;
	float imag;

public:
	Complex(float real, float imag) : real(real), imag(imag) {}

	Complex operator +(Complex num) const {
		return Complex(real + num.real, imag + num.imag);
	}

	void print() const {
		cout << "(" << real << "," << imag << ")" << endl;
	}

	Complex add(Complex num) const {
		return Complex(real + num.real, imag + num.imag);
	}

	friend Complex operator -(Complex num) {
		return Complex(-num.real, -num.imag);
	}

	friend ostream& operator <<(ostream& s, const Complex& num) {
		return s << "(" << num.real << "," << num.imag << ")";
	}

	friend Complex operator *(Complex left, Complex right) {
		return Complex((left.real*right.real)-(left.imag*right.imag), (left.real*right.imag)+(left.imag*right.real));
	}

};


int main() {
	const Complex a(1.2, 2.0); // create a complex number with real=1.2 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using a friend function
	c.print(); // should print the following to cout: (1.5,2.0)
	
	// (member syntax).  Should look the same as method add where the name add
	// is replaced by operator +
	
	const Complex d = a.add(b); // this should be the same as the above except the name
	d.print();
	
	Complex e = -d; // implement unary - using a member operator. Since it has one parameter which is this should have ZERO PARAMETERS!!!
	cout << e << '\n';
}
