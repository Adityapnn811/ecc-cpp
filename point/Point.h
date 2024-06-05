#ifndef POINT_H
#define POINT_H

#include <string>
#include "math/math.h"

class Point {
    private:
        LL x;
        LL y;
    public:
        Point(LL x, LL y);
        Point add(const Point& other, LL p);
        Point substract(const Point& other, LL p);
        Point multiply(const LL& scalar, LL a, LL p);
        Point double_point(LL a, LL p);
        bool isInfinite();
        bool isOnCurve(LL a, LL b, LL p);
        std::string to_string();
};

#endif // POINT_H