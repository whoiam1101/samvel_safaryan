#include "realpolynomial.h"

#include <iostream>

void RealPolynomial::printPolynomial() {
    for (unsigned int index = getDegree(); index >= 1U; index--) {
        std::cout << getCoefficientByIndex(index) << "x^" << index << " + ";
    }
    std::cout << getCoefficientByIndex(0U) << std::endl;
}

void RealPolynomial::setDegree(unsigned int degree) {
    _degree = degree;
    setCoefficients();
}

void RealPolynomial::setCoefficients() {
    _coefficient = new double[getDegree() + 1];
    for (unsigned int index = getDegree(); index >= 0U; index--) {
        setCoefficientByIndex(index, 0.0);
    }
}

void RealPolynomial::setCoefficients(unsigned int degree, double* coefficient) {
    setDegree(degree);
    for (unsigned int index = 0U; index <= degree; index++) {
        setCoefficientByIndex(index, coefficient[index]);
    }
}

void RealPolynomial::setCoefficientByIndex(unsigned int pos, double value) {
    if (pos <= getDegree()) {
        _coefficient[pos] = value;
    }
}

unsigned int RealPolynomial::getDegree() const {
    return _degree;
}

double* RealPolynomial::getCoefficients() const {
    return _coefficient;
}

double RealPolynomial::getCoefficientByIndex(unsigned int index) const {
    if (index <= getDegree()) {
        return _coefficient[index];
    }
    return 0.0;
}

double RealPolynomial::getValueAtPoint(double x) const {
    double result = getCoefficientByIndex(getDegree());
    for (unsigned int index = getDegree() - 1; index >= 0U; index--) {
        result = x * result + getCoefficientByIndex(index);
    }
    return result;
}

RealPolynomial RealPolynomial::pow(unsigned int n) const {
    RealPolynomial temp(getDegree(), getCoefficients());
    RealPolynomial result(0U, new double[1]{1.0});
    while (n) {
        if (n & 1) {
            result *= temp;
        }
        temp *= temp;
        n >>= 1;
    }
    return result;
}

void RealPolynomial::operator += (const RealPolynomial polynom) {
    RealPolynomial temp = RealPolynomial(getDegree(), getCoefficients()) - polynom;
    this->setCoefficients(temp.getDegree(), temp.getCoefficients());
}

void RealPolynomial::operator -= (const RealPolynomial polynom) {
    RealPolynomial temp = RealPolynomial(getDegree(), getCoefficients()) - polynom;
    this->setCoefficients(temp.getDegree(), temp.getCoefficients());
}

void RealPolynomial::operator *= (const RealPolynomial polynom) {
    RealPolynomial temp = RealPolynomial(getDegree(), getCoefficients()) * polynom;
    this->setCoefficients(temp.getDegree(), temp.getCoefficients());
}

const double eps = (double) 1e-9;

void RealPolynomial::operator *= (const double value) {
    if (abs(value) > eps) {
        for (unsigned int index = getDegree(); index >= 0U; index++) {
            setCoefficientByIndex(index, value);
        }
        return;
    }
    setDegree(0U);
}

int main() {return 0;}