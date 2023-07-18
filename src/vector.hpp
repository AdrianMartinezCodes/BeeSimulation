#ifndef VECTOR_H
#define VECTOR_H
#include <ostream>

class Vector {
public:
    Vector();
    Vector(double x, double y);

    double getX() const;
    double getY() const;
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);

private:
    double x;
    double y;
};

#endif  // VECTOR_H
