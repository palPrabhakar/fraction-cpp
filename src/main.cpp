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

  SECTION("Test Equality") {
    REQUIRE_FALSE(f1 == f2);
    REQUIRE(f1 != f2);

    REQUIRE(f1 == Fraction(4, 8));
    REQUIRE_FALSE(f1 != Fraction(4, 8));

    REQUIRE_FALSE(f4 == f7);
    REQUIRE(f4 != f7);

    REQUIRE(f3 == Fraction(3, 9));
    REQUIRE_FALSE(f3 != Fraction(3, 9));

    REQUIRE(f5 == Fraction(-3, 4));
    REQUIRE_FALSE(f5 != Fraction(-3, 4));

    REQUIRE(f5 == f5);
    REQUIRE_FALSE(f5 != f5);
  }

  SECTION("Test Addition") {
    CHECK(f1 + f2 == Fraction(13, 14));
    CHECK(f1 + f3 == Fraction(5, 6));
    CHECK(f1 + f4 == Fraction(17, 14));
    CHECK(f2 + f5 == Fraction(-9, 28));
    CHECK(f2 + f6 == Fraction(1, 35));
    CHECK(f3 + f7 == f3);
    CHECK(f5 + f6 == Fraction(-23, 20));
  }

  SECTION("Test Subtraction") {
    CHECK(f1 - f2 == Fraction(1, 14));
    CHECK(f1 - f3 == Fraction(1, 6));
    CHECK(f1 - f4 == Fraction(-3, 14));
    CHECK(f2 - f5 == Fraction(33, 28));
    CHECK(f2 - f6 == Fraction(29, 35));
    CHECK(f3 - f7 == f3);
    CHECK(f5 - f6 == Fraction(-7, 20));
  }

  SECTION("Test Multiplication") {
    CHECK(f1 * f2 == Fraction(3, 14));
    CHECK(f1 * f3 == Fraction(1, 6));
    CHECK(f1 * f4 == Fraction(5, 14));
    CHECK(f2 * f5 == Fraction(-9, 28));
    CHECK(f2 * f6 == Fraction(-6, 35));
    CHECK(f3 * f7 == f7);
    CHECK(f5 * f6 == Fraction(3, 10));
  }

  SECTION("Test Division") {
    CHECK(f1 / f2 == Fraction(7, 6));
    CHECK(f1 / f3 == Fraction(3, 2));
    CHECK(f1 / f4 == Fraction(7, 10));
    CHECK(f2 / f5 == Fraction(-4, 7));
    CHECK(f2 / f6 == Fraction(-15, 14));
    CHECK_THROWS_AS(f3 / f7, invalid_argument);
    CHECK(f5 / f6 == Fraction(15, 8));
  }

  SECTION("Test Comparison") {
    CHECK(f1 > f2);
    CHECK_FALSE(f1 < f2);
    CHECK(f1 >= f2);
    CHECK_FALSE(f1 <= f2);

    CHECK(f2 > f3);
    CHECK_FALSE(f2 < f3);
    CHECK(f2 >= f3);
    CHECK_FALSE(f2 <= f3);

    CHECK(f4 > f5);
    CHECK_FALSE(f4 < f5);
    CHECK(f4 >= f5);
    CHECK_FALSE(f4 <= f5);

    CHECK(f4 > f7);
    CHECK_FALSE(f4 < f7);
    CHECK(f4 >= f7);
    CHECK_FALSE(f4 <= f7);
  }
}
