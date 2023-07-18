#include <catch2/catch_all.hpp>
#include "vector.hpp"

TEST_CASE("Vector - getX and getY") {
    Vector v(1.2, -3.4);

    SECTION("getX returns the correct value") {
        REQUIRE(v.getX() == 1.2);
    }

    SECTION("getY returns the correct value") {
        REQUIRE(v.getY() == -3.4);
    }
}
