#include "math.h"
#include <random>
#include <stdio.h>

LL* gcdExtended(LL a, LL b) {
    LL* result = new LL[2];
    if (a == 0) {
        result[0] = b;
        result[1] = 0;
        return result;
    }
    LL x = 0, y = 1, lastx = 1, lasty = 0;
    LL temp = 0, temp2 = a, temp1 = b, q = 0;
    while (temp1 != 0) {
        q = temp2 / temp1;
        temp = temp2;
        temp2 = temp1;
        temp1 = temp - q * temp1;
        temp = x;
        x = lastx - q * x;
        lastx = temp;
        temp = y;
        y = lasty - q * y;
        lasty = temp;
    }
    result[0] = lastx;
    result[1] = lasty;
    return result;
}

LL* tonelliShanks(LL a, LL m) {
    LL* result = new LL[2];
    if (powMod(a, (m - 1) / 2, m) != 1) {
        return result;
    }
    LL q = m - 1;
    LL s = 0;
    while ((q & 1) == 0) {
        q /= 2;
        s+=1;
    }
    if (s == 1) {
        LL r = powMod(a, (m + 1) / 4, m);
        if (powMod(r, 2, m) == a) {
            result[0] = r;
            result[1] = m - r;
            return result;
        }
    }
    LL z = 1;
    while (powMod(z, (m - 1) / 2, m) != m - 1) {
        z+=1;
    }
    LL c = powMod(z, q, m);
    LL r = powMod(a, (q + 1) / 2, m);
    LL t = powMod(a, q, m);
    LL m1 = s;
    while (t != 1) {
        LL temp = t;
        LL i = 0;
        while (temp != 1) {
            temp = powMod(temp, 2, m);
            i+=1;
        }
        LL b = powMod(c, powMod(2, m1 - i - 1, m - 1), m);
        LL b2 = powMod(b, 2, m);
        r = mod((r * b), m);
        t = mod((t * b2) , m);
        c = b2;
        m1 = i;
    }
    result[0] = r;
    result[1] = m - r;
    return result;
}

LL powMod(LL base, LL exp, LL m) {
    LL result = 1;
    base = mod(base, m);
    while (exp > 0) {
        if (mod(exp, 2) == 1) {
            result = mod((result * base), m);
        }
        exp = exp >> 1;
        base = mod((base * base), m);
    }
    return result;
}

LL mod(LL a, LL mod) {
    return ((a % mod) + mod) % mod;
}

LL llrand(){
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> randDis(100*100*100, RAND_MAX);
    if (sizeof(int) < sizeof(LL)){

        return (static_cast<LL>(randDis(dev)) << (sizeof(int) * 8)) |
               randDis(dev);
    }

    return randDis(dev);
}
}