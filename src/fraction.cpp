#include "fraction.h"
#include <iostream>
#include <numeric>
#include <stdexcept>

Fraction::Fraction() : n(0), d(1) {}

Fraction::Fraction(int num, int den) {
  if (den == 0) {
    throw std::invalid_argument("Denominator cannot be zero.\n");
  } else if (num == 0) {
    n = 0;
    d = 1;
  } else {
    int sign = 1.0;
    if (num < 0) {
      sign *= -1;
      num *= -1;
    }
    if (den < 0) {
      sign *= -1;
      den *= -1;
    }

    n = (num * sign) / std::gcd(num, den);
    d = den / std::gcd(num, den);
  }
}

std::ostream &operator<<(std::ostream &os, const Fraction &d) {
  if (d.d == 1)
    os << d.n;
  else
    os << d.n << "/" << d.d;

  return os;
}

Fraction Fraction::operator+(const Fraction &rhs) const {
  return Fraction(n * rhs.d + d * rhs.n, d * rhs.d);
}

Fraction Fraction::operator-(const Fraction &rhs) const {
  return Fraction(n * rhs.d - d * rhs.n, d * rhs.d);
}

Fraction Fraction::operator*(const Fraction &rhs) const {
  return Fraction(n * rhs.n, d * rhs.d);
}

Fraction Fraction::operator/(const Fraction &rhs) const {
  return Fraction(n * rhs.d, d * rhs.n);
}

bool operator==(const Fraction &lhs, const Fraction &rhs) {
  return (lhs.n == rhs.n) && (lhs.d == rhs.d);
}

bool operator!=(const Fraction &lhs, const Fraction &rhs) {
  return !(lhs == rhs);
}

bool operator<(const Fraction &lhs, const Fraction &rhs) {
  Fraction r;
  r = lhs - rhs;

  if (r.n < 0)
    return true;
  else
    return false;
}

bool operator>(const Fraction &lhs, const Fraction &rhs) { return rhs < lhs; }

bool operator<=(const Fraction &lhs, const Fraction &rhs) {
  return !(lhs > rhs);
}

bool operator>=(const Fraction &lhs, const Fraction &rhs) {
  return !(lhs < rhs);
}
