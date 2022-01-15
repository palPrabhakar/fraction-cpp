#include "fraction.h"
#include <climits>
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

std::ostream &operator<<(std::ostream &os, const Fraction &f) {
  if (f.den() == 1)
    os << f.num();
  else
    os << f.num() << "/" << f.den();

  return os;
}

Fraction operator+(const Fraction &lhs, const Fraction &rhs) {
  long long n =
      (long long)lhs.num() * rhs.den() + (long long)lhs.den() * rhs.num();
  long long d = (long long)lhs.den() * rhs.den();

  check_operands(n, d);

  return Fraction(n, d);
}

Fraction operator-(const Fraction &lhs, const Fraction &rhs) {
  long long n =
      (long long)lhs.num() * rhs.den() - (long long)lhs.den() * rhs.num();
  long long d = (long long)lhs.den() * rhs.den();

  check_operands(n, d);

  return Fraction(n, d);
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs) {
  long long n = (long long)lhs.num() * rhs.num();
  long long d = (long long)lhs.den() * rhs.den();

  check_operands(n, d);

  return Fraction(n, d);
}

Fraction operator/(const Fraction &lhs, const Fraction &rhs) {
  long long n = (long long)lhs.num() * rhs.den();
  long long d = (long long)lhs.den() * rhs.num();

  check_operands(n, d);

  return Fraction(n, d);
}

bool operator==(const Fraction &lhs, const Fraction &rhs) {
  return (lhs.num() == rhs.num()) && (lhs.den() == rhs.den());
}

bool operator!=(const Fraction &lhs, const Fraction &rhs) {
  return !(lhs == rhs);
}

bool operator<(const Fraction &lhs, const Fraction &rhs) {
  Fraction r;
  r = lhs - rhs;

  if (r.num() < 0)
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

void check_operands(long long &n, long long &d) {
  if (check_overflow(n) || check_overflow(d)) {
    long long div = std::gcd(n, d);
    if (check_overflow(n / div) || check_overflow(d / div)) {
      throw std::runtime_error(
          "Operation leads to either overflow or underlow");
    } else {
      n /= div;
      d /= div;
    }
  }
}

bool check_overflow(long long value) {
  if (value < INT_MIN || value > INT_MAX)
    return true;

  return false;
}
