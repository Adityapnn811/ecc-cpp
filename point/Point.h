#ifndef POINT_H
#define POINT_H

#include "bignum/bignum.h"

class Point {
    private:
        bignum x;
        bignum y;
    public:
        Point(bignum x, bignum y);
        Point operator+(const Point& other);
        Point operator-(const Point& other);
        Point operator*(const bignum& scalar);
        Point double_point();
        bignum getX();
        bignum getY();
        void setX(bignum x);
        void setY(bignum y);
        std::string to_string();
};

#endif // POINT_H