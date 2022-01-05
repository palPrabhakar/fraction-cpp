#include "fraction.h"
#include <iostream>

using namespace std;

int main() {
  Fraction a(1, 3);
  Fraction b(3, 28);
  Fraction c;

  c = a + b;
  cout << c << "\t(should be 37/84)" << endl;

  c = a - b;
  cout << c << "\t(should be 19/84)" << endl;

  c = a * b;
  cout << c << "\t(should be 1/28)" << endl;

  c = a / b;
  cout << c << "\t(should be 28/9)" << endl;

  cout << a << endl;
  cout << b << endl;

  Fraction d(1, 2);
  Fraction e(2, 3);

  cout << "comparison" << endl;
  cout << (d < e) << endl;

  Fraction f(1, 2);
  Fraction g(4, 8);

  cout << (f < g) << endl;

  // c = -1 * b;
  // cout << c << "\t(should be -3/28)" << endl;

  // c = b * (-1);
  // cout << c << "\t(should be -3/28)" << endl;

  return 0;
}
