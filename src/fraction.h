#ifndef FRACTION_H
#define FRACTION_H

#include <ostream>

class Fraction {
public:
  Fraction();
  Fraction(int, int);

  Fraction operator+(const Fraction &) const;
  Fraction operator-(const Fraction &) const;
  Fraction operator*(const Fraction &) const;
  Fraction operator/(const Fraction &) const;

  friend bool operator<(const Fraction &, const Fraction &);
  friend bool operator>(const Fraction &, const Fraction &);
  friend bool operator<=(const Fraction &, const Fraction &);
  friend bool operator>=(const Fraction &, const Fraction &);
  friend bool operator==(const Fraction &, const Fraction &);
  friend bool operator!=(const Fraction &, const Fraction &);

  friend std::ostream &operator<<(std::ostream &, Fraction const &);

  int numerator() { return n; }
  int denominator() { return d; }

private:
  int n, d;
};

#endif /* ifndef FRACTION_H */
