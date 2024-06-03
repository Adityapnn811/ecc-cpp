#include "bignum/bignum.h"
#include <stdio.h>

int main() {
    bignum b14 = bignum(2147483647) * bignum(2147483647);
    bignum b15 = b14 * b14;
    bignum b19 = b15 / b14;
    printf("b14 = %s\n", b19.to_string().c_str());
    return 0;
}