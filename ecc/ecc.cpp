#include "ecc.h"

#define K 10

LL size8[6] = {0x80, 0x40, 0xa3, 0x5d, 0x40, 0x9c};
LL size12[6] = {0x057a, 0x0260, 0x0cf1, 0x0693, 0x0b15, 0x0cc6};
LL size16[6] = {0x6c5b, 0xa109, 0xad5f, 0x1658, 0x0f13, 0xae3c};
LL size20[6] = {0x0b6c5b, 0x0bc293, 0x0d6a1d, 0x03995f, 0x028bf3, 0x0d6bb4};
LL size24[6] = {0x6594df, 0x06f010, 0x87986b, 0x0910d4, 0x42451a, 0x87a7d6};
LL size32[6] = {0x8540bd90, 0x534b2d74, 0xa074be25, 0x48bb1305, 0x0aa3b329, 0xa07432d9};

ECC::ECC() {
    this->a = size24[0];
    this->b = size24[1];
    this->p = size24[2];
    this->G = Point(size24[3], size24[4]);
    this->n = size24[5];
}

void ECC::generateKeyPair(LL* privateKeyRes, Point* publicKeyRes) {
    *privateKeyRes = mod(llrand(), (this->n - 1)) ;

    *publicKeyRes = this->G.multiply(*privateKeyRes, this->a, this->p);
}

Point ECC::encodeMessage(LL message) {
    int k = K;
    LL ctr = message + 1;
    if (ctr * k < this->p) {
        int j = 0;
        while (j < k) {
            LL x = message * k + j;
            LL y2 = mod(((x * x * x)+ (this->a * x) + this->b) , this->p);
            LL y = tonelliShanks(y2, this->p)[0];
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
    LL k = mod(llrand(), this->n);
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