#include <iostream>
using namespace std;

class B {
  int x;
public:
  B (int i = 17) { x = i; }
  int get_x () { return x; }
  operator int() { return x; }
};

class D : public B {
public:
  D (int i = -16) : B(i) {}
};

int main (int argc, char const *argv[])
{
  D a;
  cout << 27 + a; // afiseaza 11
  
  return 0;
}