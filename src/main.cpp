#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "fraction.h"
#include <iostream>

using namespace std;

TEST_CASE("Init Fractions", "[fractions]") {
  Fraction f1(1, 2);
  Fraction f2(3, 7);
  Fraction f3(-1, -3);
  Fraction f4(30, 42);
  Fraction f5(3, -4);
  Fraction f6(-2, 5);
  Fraction f7(0, -4);

  SECTION("Construction") {
    CHECK_THROWS_AS(Fraction(1, 0), invalid_argument);
    CHECK_THROWS_AS(Fraction(0, 0), invalid_argument);
    CHECK(((f1.numerator() == 1) && (f1.denominator() == 2)));
    CHECK(((f2.numerator() == 3) && (f2.denominator() == 7)));
    CHECK(((f3.numerator() == 1) && (f3.denominator() == 3)));
    CHECK(((f4.numerator() == 5) && (f4.denominator() == 7)));
    CHECK(((f5.numerator() == -3) && (f5.denominator() == 4)));
    CHECK(((f6.numerator() == -2) && (f6.denominator() == 5)));
    CHECK(((f7.numerator() == 0) && (f7.denominator() == 1)));
  }

  SECTION("Test Addition") {
    Fraction fa12 = f1 + f2;
    CHECK(((fa12.numerator() == 13) && (fa12.denominator() == 14)));

    Fraction fa13 = f1 + f3;
    CHECK(((fa13.numerator() == 5) && (fa13.denominator() == 6)));

    Fraction fa14 = f1 + f4;
    CHECK(((fa14.numerator() == 17) && (fa14.denominator() == 14)));

    Fraction fa25 = f2 + f5;
    CHECK(((fa25.numerator() == -9) && (fa25.denominator() == 28)));

    Fraction fa26 = f2 + f6;
    CHECK(((fa26.numerator() == 1) && (fa26.denominator() == 35)));

    Fraction fa37 = f3 + f7;
    CHECK(((fa37.numerator() == f3.numerator()) &&
           (fa37.denominator() == f3.denominator())));

    Fraction fa56 = f5 + f6;
    CHECK(((fa56.numerator() == -23) && (fa56.denominator() == 20)));
  }

  SECTION("Test Subtraction") {
    Fraction fs12 = f1 - f2;
    CHECK(((fs12.numerator() == 1) && (fs12.denominator() == 14)));

    Fraction fs13 = f1 - f3;
    CHECK(((fs13.numerator() == 1) && (fs13.denominator() == 6)));

    Fraction fs14 = f1 - f4;
    CHECK(((fs14.numerator() == -3) && (fs14.denominator() == 14)));

    Fraction fs25 = f2 - f5;
    CHECK(((fs25.numerator() == 33) && (fs25.denominator() == 28)));

    Fraction fs26 = f2 - f6;
    CHECK(((fs26.numerator() == 29) && (fs26.denominator() == 35)));

    Fraction fs37 = f3 - f7;
    CHECK(((fs37.numerator() == f3.numerator()) &&
           (fs37.denominator() == f3.denominator())));

    Fraction fs56 = f5 - f6;
    CHECK(((fs56.numerator() == -7) && (fs56.denominator() == 20)));
  }
}
