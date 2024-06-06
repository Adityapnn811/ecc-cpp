#include "ecc.h"

#define K 10

ECC::ECC() {
    this->a = 0x6c5b;
    this->b = 0xa109;
    this->p = 0xad5f;
    this->G = Point(0x1658, 0x0f13);
    this->n = 0xae3c;
}

void ECC::generateKeyPair(LL* privateKeyRes, Point* publicKeyRes) {
    *privateKeyRes = llrand() % (this->n - 1) ;

    *publicKeyRes = this->G.multiply(*privateKeyRes, this->a, this->p);
}

Point ECC::encodeMessage(LL message) {
    int k = K;
    LL ctr = message + 1;
    if (ctr * k < this->p) {
        int j = 0;
        while (j < k) {
            LL x = message * k + j;
            LL y2 = (((x * x * x) % this->p )+ ((this->a * x) % this->p) + this->b) % this->p;
            LL y = tonelliShanks(y2, this->p)[0];
            printf("y = %lld\n", y);
            if (y != 0) {
                return Point(x, y);
            }
            j++;
        }
    } else {
        return Point(0, 0);
    }
    return Point(0, 0);
}

LL ECC::decodeMessage(Point message) {
    int k = K;
    return (message.getX()) / k;
}

Point* ECC::encryptMessage(Point message, Point publicKey) {
    Point* result = new Point[2];
    LL k = llrand() % this->n;
    Point c1 = this->G.multiply(k, this->a, this->p);
    Point publicKeyK = publicKey.multiply(k, this->a, this->p);
    Point c2 = message.add(publicKeyK, this->p);
    // C1 is the random point
    result[0] = c1;
    // C2 is the encrypted message
    result[1] = c2;
    return result;
}

Point ECC::decryptMessage(Point* ciphertext, LL privateKey) {
    Point c1 = ciphertext[0];
    Point kGPrivate = c1.multiply(privateKey, this->a, this->p);
    Point c2 = ciphertext[1];
    Point decrypted = c2.substract(kGPrivate, this->p);
    return decrypted;
}