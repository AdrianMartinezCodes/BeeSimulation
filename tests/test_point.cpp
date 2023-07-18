#include <catch2/catch_all.hpp>
#include "point.hpp"

TEST_CASE("Point - getX and getY") {
    Point p(3.0, 4.0);

    SECTION("getX returns the correct value") {
        REQUIRE(p.getX() == 3.0);
    }

    SECTION("getY returns the correct value") {
        REQUIRE(p.getY() == 4.0);
    }
}

TEST_CASE("Point - operator<<") {
    Point p(2.5, -1.8);

    SECTION("operator<< returns the correct string representation") {
        std::ostringstream oss;
        oss << p;
        REQUIRE(oss.str() == "(2.5, -1.8)");
    }
}
