#include <catch2/catch_all.hpp>
#include "flower.hpp"

TEST_CASE("Flower - getNegativeCharge and getLocation") {
    Point location(1.0, 2.0);
    Flower f(0.5, location);

    SECTION("getNegativeCharge returns the correct value") {
        REQUIRE(f.getNegativeCharge() == 0.5);
    }

    SECTION("getLocation returns the correct value") {
        REQUIRE(f.getLocation() == location);
    }
}

TEST_CASE("Flower - getVectorTo and getDistanceTo") {
    Point location(1.0, 2.0);
    Flower f(0.5, location);

    SECTION("getVectorTo returns the correct vector") {
        Point point(3.0, 4.0);
        Vector expectedVector(0.25, 0.25);
        Vector vector = f.getVectorTo(point);
        REQUIRE(vector.getX() == Catch::Approx(expectedVector.getX()));
        REQUIRE(vector.getY() == Catch::Approx(expectedVector.getY()));
    }

    SECTION("getDistanceTo returns the correct squared distance") {
        Point point(3.0, 4.0);
        double expectedDistanceSquared = 2.8284271247461903 * 2.8284271247461903;
        double distanceSquared = f.getDistanceSquaredTo(point);
        REQUIRE(distanceSquared == Catch::Approx(expectedDistanceSquared));
    }
}
