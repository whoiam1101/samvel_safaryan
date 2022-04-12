#include "complex.h"

#include <cmath>

const double eps = 1.0e-10;
const double PI  = 3.1415926535897932384626433832795;

void Complex::setRealPart(double number) {
    _real_part = number;
    setArgument();
    setNorm();
}

void Complex::setImaginaryPart(double number) {
    _imaginary_part = number;
    setArgument();
    setNorm();
}

void Complex::setRealPart() {
    setRealPart(getNorm() * cos(getArgument()));
}

void Complex::setImaginaryPart() {
    setImaginaryPart(getNorm() * sin(getArgument()));
}

void Complex::setArgument(double angle) {
    _argument = angle;
    setRealPart();
    setImaginaryPart();
}

void Complex::setNorm(double number) {
    if (number > eps) {
        _norm = number;
        setRealPart();
        setImaginaryPart();
    }
}

void Complex::setArgument() {
    _argument = atan(getImaginaryPart() / getRealPart());
}

void Complex::setNorm() {
    _norm = sqrt(getRealPart() * getRealPart() + getImaginaryPart() * getImaginaryPart());
}

double Complex::getRealPart() const {
    return _real_part;
}

double Complex::getImaginaryPart() const {
    return _imaginary_part;
}

double Complex::getArgument() const {
    return _argument;
}

double Complex::getNorm() const {
    return _norm;
}

double Complex::getSqrNorm() const {
    return getNorm() * getNorm();
}

Complex Complex::conjugate() const {
    return Complex(_real_part, -_imaginary_part);
}

Complex Complex::pow(int n) const {
    bool isnegative = false;
    if (n < 0) {
        isnegative = true;
        n = -n;
    }
    Complex temp(_real_part, _imaginary_part);
    Complex result(1.0, 0.0);
    while (n) {
        if (n & 1) {
            temp = temp * temp;
        }
        result = result * temp;
        n >>= 1;
    }
    if (isnegative) {
        return Complex(1.0, 0.0) / result;
    }
    return result;
}