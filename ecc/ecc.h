#ifndef ECC_H
#define ECC_H

#include "math/math.h"
#include "point/point.h"

class ECC {
    public:
        LL a, b, p, n;
        Point G;

        ECC();
        void generateKeyPair(LL* privateKeyRes, Point* publicKeyRes);
        Point encodeMessage(LL message);
        LL decodeMessage(Point message);
        Point* encryptMessage(Point message, Point publicKey);
        Point decryptMessage(Point* message, LL privateKey);
};


#endif