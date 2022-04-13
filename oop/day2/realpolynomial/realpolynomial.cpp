#include "realpolynomial.h"

#include <iostream>

void RealPolynomial::setLambda(double lambda) {
    _lambda = lambda;
}

double RealPolynomial::getLambda() const {
    return _lambda;
}

const double eps = (double) 1e-9;

void RealPolynomial::printPolynomial() {
    for (unsigned int index = this->getDegree(); index >= 1U; index--) {
        if (abs(this->getCoefficientByIndex(index)) > eps) {
            std::cout << this->getCoefficientByIndex(index) << "x^" << index << " + ";
        }
    }
    std::cout << this->getCoefficientByIndex(0U) << std::endl;
}

void RealPolynomial::setDegree(unsigned int degree) {
    _degree = degree;
    this->setLambda(1.0);
    this->setCoefficients();
}

void RealPolynomial::setCoefficients() {
    _coefficient = new double[this->getDegree() + 1];
    for (unsigned int index = this->getDegree(); index >= 0U; index--) {
        this->setCoefficientByIndex(index, 0.0);
    }
}

void RealPolynomial::setCoefficients(unsigned int degree, double* coefficient) {
    this->setDegree(degree);
    for (unsigned int index = 0U; index <= degree; index++) {
        this->setCoefficientByIndex(index, coefficient[index]);
    }
}

void RealPolynomial::setCoefficientByIndex(unsigned int pos, double value) {
    if (pos <= this->getDegree()) {
        _coefficient[pos] = value;
    }
}

unsigned int RealPolynomial::getDegree() const {
    return _degree;
}

double* RealPolynomial::getCoefficients() const {
    double* coefficient = new double[this->getDegree() + 1];
    for (unsigned int index = 0U; index <= this->getDegree(); index++) {
        coefficient[index] = this->getCoefficientByIndex(index);
    }
    return coefficient;
}

double RealPolynomial::getCoefficientByIndex(unsigned int index) const {
    if (index <= this->getDegree()) {
        return _coefficient[index] * this->getLambda();
    }
    return 0.0;
}

double RealPolynomial::getValueAtPoint(double x) const {
    double result = this->getCoefficientByIndex(this->getDegree());
    for (unsigned int index = this->getDegree() - 1; index >= 0U; index--) {
        result = x * result + this->getCoefficientByIndex(index);
    }
    return result;
}

RealPolynomial RealPolynomial::pow(unsigned int n) const {
    RealPolynomial temp(this->getDegree(), this->getCoefficients());
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

void RealPolynomial::operator += (const RealPolynomial& polynom) {
    RealPolynomial temp = RealPolynomial(getDegree(), getCoefficients()) + polynom;
    this->setCoefficients(temp.getDegree(), temp.getCoefficients());
}

void RealPolynomial::operator -= (const RealPolynomial& polynom) {
    RealPolynomial temp = RealPolynomial(getDegree(), getCoefficients()) - polynom;
    this->setCoefficients(temp.getDegree(), temp.getCoefficients());
}

void RealPolynomial::operator *= (const RealPolynomial& polynom) {
    RealPolynomial temp = RealPolynomial(getDegree(), getCoefficients()) * polynom;
    this->setCoefficients(temp.getDegree(), temp.getCoefficients());
}

void RealPolynomial::operator *= (const double& value) {
    if (abs(value) > eps) {
        this->setLambda(this->getLambda() * value);
        return;
    }
    this->setDegree(0U);
}