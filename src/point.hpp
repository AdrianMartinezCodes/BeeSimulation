#ifndef POINT_H
#define POINT_H

#include <ostream>

class Point {
public:
    Point();
    Point(double x, double y);

    double getX() const;
    double getY() const;

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    bool operator==(const Point& other) const;

private:
    double x;
    double y;
};

#endif  // POINT_H
