#ifndef MATH_H
#define MATH_H

#define LL long long

// Return an array of bignums containing the prime factors of n
LL* gcdExtended(LL a, LL b);

// Calculate modular inverse using tonelli shanks
LL* tonelliShanks(LL a, LL m);

// Calculate the exponent and modulus of a number
LL powMod(LL base, LL exp, LL mod);

// Calculate the modulo
LL mod(LL a, LL mod);


#endif