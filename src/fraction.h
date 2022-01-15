#ifndef FRACTION_H
#define FRACTION_H

#include <ostream>

class Fraction {
public:
  Fraction();
  Fraction(int, int);

  int num() const { return n; }
  int den() const { return d; }

private:
  int n, d;
};

Fraction operator+(const Fraction &, const Fraction &);
Fraction operator-(const Fraction &, const Fraction &);
Fraction operator*(const Fraction &, const Fraction &);
Fraction operator/(const Fraction &, const Fraction &);
bool operator<(const Fraction &, const Fraction &);
bool operator>(const Fraction &, const Fraction &);
bool operator<=(const Fraction &, const Fraction &);
bool operator>=(const Fraction &, const Fraction &);
bool operator==(const Fraction &, const Fraction &);
bool operator!=(const Fraction &, const Fraction &);
std::ostream &operator<<(std::ostream &, Fraction const &);
bool check_overflow(long long);
void check_operands(long long &, long long &);

#endif /* ifndef FRACTION_H */
