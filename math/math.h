#ifndef MATH_H
#define MATH_H

#include "bignum.h"

// Return an array of bignums containing the prime factors of n
bignum* gcdExtended(bignum a, bignum b);

// Calculate modular inverse using tonelli shanks
bignum* tonelliShanks(bignum a, bignum m);

// Calculate the exponent and modulus of a number
bignum powMod(bignum base, bignum exp, bignum mod);


#endif