#include "math/math.h"
#include "point/Point.h"
#include <stdio.h>

int main() {
    // Test the gcdExtended function
    LL* resGcd = gcdExtended(3213, 3213213);
    printf("[%lld, %lld]\n", resGcd[0], resGcd[1]);

    // Test the tonelliShanks function
    LL* resTonelli = tonelliShanks(8, 17);
    printf("[%lld, %lld]\n", resTonelli[0], resTonelli[1]);

    // Test the powMod function
    LL resPowMod = powMod(321, 233, 1455);
    printf("%lld\n", resPowMod);

    // Test points
    LL a = 2;
    // LL a = 0xFFFFFFFDFFFFFFFFFFFFFFFFFFFFFFFC;
    printf("a = %lld\n", a);
    // LL b = 0xE87579C11079F43DD824993C2CEE5ED3;
    // LL p = 10997031918897188677;
    LL p = 17;
    Point p1 = Point(5, 1);
    Point p2 = Point(7, 3);

    Point p3 = p1.add(p2, p);
    printf("p2+ p1 = %s\n", p3.to_string().c_str());
    p1 = p1.double_point(a, p);
    p1 = p1.double_point(a, p);
    p1 = p1.double_point(a, p);
    // p1 = p1.double_point(a, p);
    printf("Double p1: %s\n", p1.to_string().c_str());
    return 0;
}