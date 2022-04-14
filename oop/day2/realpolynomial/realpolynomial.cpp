#include "realpolynomial.h"

#include <iostream>

const double eps = (double) 1e-9;

void RealPolynomial::refactorDegree() {
    int degree = (int) this->getDegree();
    while (degree >= 0 && abs(this->getCoefficientByIndex(degree)) <= eps) {
        degree--;
    }
    if (degree == -1) {
        degree = 0;
    }
    double* coefficient = new double[degree + 1];
    for (unsigned int index = 0U; index <= (unsigned int) degree; index++) {
        coefficient[index] = this->getCoefficientByIndex(index);
    }
    this->setCoefficients(degree, coefficient);
}

void RealPolynomial::setLambda(double lambda) {
    _lambda = lambda;
}

double RealPolynomial::getLambda() const {
    return _lambda;
}

void RealPolynomial::setDegree(unsigned int degree) {
    _degree = degree;
}

void RealPolynomial::setCoefficients(unsigned int degree, double* coefficient) {
    this->setDegree(degree);
    _coefficient = new double[this->getDegree() + 1];
    for (unsigned int index = 0U; index <= this->getDegree(); index++) {
        this->setCoefficientByIndex(index, coefficient[index]);
    }
    this->setLambda(1.0);
}

void RealPolynomial::setCoefficientByIndex(unsigned int pos, double value) {
    if (pos <= this->getDegree()) {
        _coefficient[pos] = value;
        /*if (pos == this->getDegree() && abs(value) <= eps) {
            this->refactorDegree();
        }*/
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
    for (int index = (int) this->getDegree() - 1; index >= 0; index--) {
        result = x * result + this->getCoefficientByIndex(index);
    }
    return result;
}

RealPolynomial RealPolynomial::pow(unsigned int n) const {
    RealPolynomial temp = *this;
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
    *this = *this + polynom;
}

void RealPolynomial::operator -= (const RealPolynomial& polynom) {
    *this = *this - polynom;
}

void RealPolynomial::operator *= (const RealPolynomial& polynom) {
    *this = *this * polynom;
}

void RealPolynomial::operator *= (const double& value) {
    if (abs(value) > eps) {
        this->setLambda(this->getLambda() * value);
        return;
    }
    this->setCoefficients(0U, new double[1]{0.0});
}

unsigned int max(unsigned int a, unsigned int b) {
    if (a > b) {
        return a;
    }
    return b;
}

RealPolynomial operator + (const RealPolynomial& first, const RealPolynomial& second) {
    unsigned int degree = max(first.getDegree(), second.getDegree());
    RealPolynomial temp(degree);
    for (unsigned int index = 0U; index <= degree; index++) {
        temp.setCoefficientByIndex(index, first.getCoefficientByIndex(index) + second.getCoefficientByIndex(index));
    }
    temp.refactorDegree();
    return temp;
}

RealPolynomial operator - (const RealPolynomial& first, const RealPolynomial& second) {
    unsigned int degree = max(first.getDegree(), second.getDegree());
    RealPolynomial temp(degree);
    for (unsigned int index = 0U; index <= degree; index++) {
        temp.setCoefficientByIndex(index, first.getCoefficientByIndex(index) - second.getCoefficientByIndex(index));
    }
    temp.refactorDegree();
    return temp;
}

RealPolynomial operator * (const RealPolynomial& first, const RealPolynomial& second) {
    RealPolynomial temp(first.getDegree() + second.getDegree());
    for (unsigned int first_index = 0U; first_index <= first.getDegree(); first_index++) {
        for (unsigned int second_index = 0U; second_index <= second.getDegree(); second_index++) {
            unsigned int index = first_index + second_index;
            temp.setCoefficientByIndex(index, temp.getCoefficientByIndex(index) +
                first.getCoefficientByIndex(first_index) * second.getCoefficientByIndex(second_index));
        }
    }
    temp.refactorDegree();
    return temp;
}

RealPolynomial operator * (const RealPolynomial& polynom, const double& value) {
    if (abs(value) > eps) {
        RealPolynomial temp = polynom;
        temp.setLambda(value);
        return temp;
    }
    return RealPolynomial(0U);
}

RealPolynomial operator * (const double& value, const RealPolynomial& polynom) {
    if (abs(value) > eps) {
        RealPolynomial temp = polynom;
        temp.setLambda(value);
        return temp;
    }
    return RealPolynomial(0U);
}

void RealPolynomial::operator = (const RealPolynomial& polynom) {
    this->setCoefficients(polynom.getDegree(), polynom.getCoefficients());
}

std::istream& operator >> (std::istream& in, RealPolynomial& polynom) {
    std::cout << "Enter degree: ";
    in >> polynom._degree;
    for (unsigned int index = 0U; index <= polynom.getDegree(); index++) {
        std::cout << "Coefficient by " << index << " index is ";
        in >> polynom._coefficient[index];
    }
    polynom.refactorDegree();
    return in;
}

std::ostream& operator << (std::ostream& out, const RealPolynomial& polynom) {
    for (unsigned int index = polynom.getDegree(); index >= 1U; index--) {
        if (abs(polynom.getCoefficientByIndex(index)) > eps) {
            out << polynom.getCoefficientByIndex(index) << "x^" << index << " + ";
        }
    }
    out << polynom.getCoefficientByIndex(0U) << std::endl;
    return out;
}

int main() {
    RealPolynomial a;
    std::cin >> a;
    return 0;
}