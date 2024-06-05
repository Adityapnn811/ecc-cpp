#include "Point.h"
#include "math.h"
#include <bitset>

Point::Point(LL x, LL y){
    this->x = x;
    this->y = y;
}
        Point Point::add(const Point& other, LL p){
            if (this->x == other.x && this->y == other.y) return this->double_point(2, p);
            
            LL dy = other.y - this->y;
            LL dx = other.x - this->x;

            if (dx < 0) {
                dx *= -1;
                dy *= -1;
            }

            dx = gcdExtended(dx, p)[0];
            LL m = (dy * dx) % p;
            LL x3 = (m * m - this->x - other.x) % p;
            LL y3 = (m * (this->x - x3) - this->y) % p;

            return Point(x3, y3);
        }

        Point Point::double_point(LL a, LL p) {
            LL m = ((3 * this->x * this->x + a) * gcdExtended(2 * this->y, p)[0]) % p;
            LL x3 = (m * m - 2 * this->x) % p;
            LL y3 = (m * (this->x - x3) - this->y) % p;

            return Point(x3, y3);
        }

        Point Point::multiply(const LL& scalar, LL a, LL p){
            Point temp = Point(this->x, this->y);
            Point result = Point(0, 0);

            // convert scalar to binary
            std::string binary = std::bitset<128>(scalar).to_string();
            for (int i = binary.length() - 1; i >= 0; i--) {
                if (binary[i] == '1') {
                    if (result.isInfinite()) {
                        result = temp;
                    } else {
                        result = result.add(temp, p);
                    }
                }
                temp = temp.double_point(a, p);
            }

            return result;
        }

        Point Point::substract(const Point& other, LL p) {
            Point temp = Point(other.x, -1 * other.y);
            return this->add(temp, p);
        }

        bool Point::isInfinite(){
            return this->x == 0 && this->y == 0;
        }

        bool Point::isOnCurve(LL a, LL b, LL p){
            return this->y == tonelliShanks((this->x * this->x * this->x + a * this->x + b) % p, p)[0];
        }

        std::string Point::to_string(){
            return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
        }