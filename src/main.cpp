#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "fraction.h"
#include <climits>
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
  Fraction fa(INT_MAX, 1);
  Fraction fa2(INT_MAX, 2);
  Fraction fb(INT_MAX - 1, 1);
  Fraction fc(INT_MIN, 1);
  Fraction fd(1, INT_MAX);
  Fraction fe(2, INT_MAX);

  SECTION("Construction") {
    CHECK_THROWS_AS(Fraction(1, 0), invalid_argument);
    CHECK_THROWS_AS(Fraction(0, 0), invalid_argument);
    CHECK(((f1.num() == 1) && (f1.den() == 2)));
    CHECK(((f2.num() == 3) && (f2.den() == 7)));
    CHECK(((f3.num() == 1) && (f3.den() == 3)));
    CHECK(((f4.num() == 5) && (f4.den() == 7)));
    CHECK(((f5.num() == -3) && (f5.den() == 4)));
    CHECK(((f6.num() == -2) && (f6.den() == 5)));
    CHECK(((f7.num() == 0) && (f7.den() == 1)));
  }

  SECTION("Test Display") {
    ostringstream os;
    os << f1;
    CHECK(os.str() == "1/2");

    os = ostringstream();
    os << f2;
    CHECK(os.str() == "3/7");

    os = ostringstream();
    os << f3;
    CHECK(os.str() == "1/3");

    os = ostringstream();
    os << f4;
    CHECK(os.str() == "5/7");

    os = ostringstream();
    os << f5;
    CHECK(os.str() == "-3/4");

    os = ostringstream();
    os << f6;
    CHECK(os.str() == "-2/5");

    os = ostringstream();
    os << f7;
    CHECK(os.str() == "0");

    os = ostringstream();
    os << Fraction(4, 1);
    CHECK(os.str() == "4");
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

    CHECK_THROWS_AS(fa + fb, std::runtime_error);
    CHECK_THROWS_AS(fa + fa2, std::runtime_error);
    CHECK(fa + fc == Fraction(-1, 1));
  }

  SECTION("Test Subtraction") {
    CHECK(f1 - f2 == Fraction(1, 14));
    CHECK(f1 - f3 == Fraction(1, 6));
    CHECK(f1 - f4 == Fraction(-3, 14));
    CHECK(f2 - f5 == Fraction(33, 28));
    CHECK(f2 - f6 == Fraction(29, 35));
    CHECK(f3 - f7 == f3);
    CHECK(f5 - f6 == Fraction(-7, 20));

    CHECK_THROWS_AS(fa - fc, std::runtime_error);
    CHECK(fa - fa2 == fa2);
    CHECK(fa - fb == Fraction(1, 1));
  }

  SECTION("Test Multiplication") {
    CHECK(f1 * f2 == Fraction(3, 14));
    CHECK(f1 * f3 == Fraction(1, 6));
    CHECK(f1 * f4 == Fraction(5, 14));
    CHECK(f2 * f5 == Fraction(-9, 28));
    CHECK(f2 * f6 == Fraction(-6, 35));
    CHECK(f3 * f7 == f7);
    CHECK(f5 * f6 == Fraction(3, 10));

    CHECK_THROWS_AS(fa * fc, std::runtime_error);
    CHECK_THROWS_AS(fa * fb, std::runtime_error);
    CHECK_THROWS_AS(fa * fa2, std::runtime_error);
    CHECK(fa * fe == Fraction(2, 1));
  }

  SECTION("Test Division") {
    CHECK(f1 / f2 == Fraction(7, 6));
    CHECK(f1 / f3 == Fraction(3, 2));
    CHECK(f1 / f4 == Fraction(7, 10));
    CHECK(f2 / f5 == Fraction(-4, 7));
    CHECK(f2 / f6 == Fraction(-15, 14));
    CHECK_THROWS_AS(f3 / f7, invalid_argument);
    CHECK(f5 / f6 == Fraction(15, 8));

    CHECK(fa / fc == Fraction(INT_MAX, INT_MIN));
    CHECK(fa / fa2 == Fraction(2, 1));
    CHECK_THROWS_AS(fa / fd, std::runtime_error);
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
