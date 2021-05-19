/*
 * Author: James Lawrence
 * I pledge my Honor that I have abided by the Stevens Honor System.
*/

using namespace std;

class A {
private:
  int* p;
public:
  A() {}
  A(int x) : p(new int[10]) { p[0] = x; }
  ~A() { delete [] p; }
};

int main() {
  A a1;
  A a2(3);
}