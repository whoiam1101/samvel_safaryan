#ifndef REALPOLYNOMIAL_REALPOLYNOMIAL_H
#define REALPOLYNOMIAL_REALPOLYNOMIAL_H

#include "../polynomial/polynomial.h"

class RealPolynomial : Polynomial {
private:
    unsigned int _degree;
    double* _coefficient;
    double _lambda;

public:
    RealPolynomial() {
        _degree = 0U;
        _coefficient = new double[1];
        _coefficient[0] = 0.0;
        _lambda = 1.0;
    }

    RealPolynomial(unsigned int degree) {
        _degree = degree;
        _coefficient = new double[_degree + 1];
        for (unsigned int index = 0U; index <= degree; index++) {
            _coefficient[index] = 0.0;
        }
        _lambda = 1.0;
    }

    RealPolynomial(
        unsigned int degree,
        double* coefficient
    ) {
        this->setCoefficients(degree, coefficient);
        this->setLambda(1.0);
    }

    void printPolynomial() override;

    void setDegree(unsigned int);
    void setCoefficients();
    void setCoefficients(unsigned int, double*);
    void setCoefficientByIndex(unsigned int, double);
    void setLambda(double);

    unsigned int getDegree() const;
    double getLambda() const;

    double* getCoefficients() const;
    double getCoefficientByIndex(unsigned int) const;
    double getValueAtPoint(double) const;

    RealPolynomial pow(unsigned int) const;

    void operator += (const RealPolynomial&);
    void operator -= (const RealPolynomial&);
    void operator *= (const RealPolynomial&);
    void operator *= (const double&);
};

RealPolynomial operator + (const RealPolynomial& first, const RealPolynomial& second) {
    unsigned int degree = (first.getDegree() > second.getDegree()) ? first.getDegree() : second.getDegree();
    RealPolynomial temp(degree);
    for (unsigned int index = 0U; index <= temp.getDegree(); index++) {
        temp.setCoefficientByIndex(index, first.getCoefficientByIndex(index) + second.getCoefficientByIndex(index));
    }
    return temp;
}

RealPolynomial operator - (const RealPolynomial& first, const RealPolynomial& second) {
    unsigned int degree = (first.getDegree() > second.getDegree()) ? first.getDegree() : second.getDegree();
    RealPolynomial temp(degree);
    for (unsigned int index = 0U; index <= degree; index++) {
        temp.setCoefficientByIndex(index, first.getCoefficientByIndex(index) - second.getCoefficientByIndex(index));
    }
    return temp;
}

RealPolynomial operator * (const RealPolynomial& first, const RealPolynomial& second) {
    RealPolynomial temp(first.getDegree() + second.getDegree());
    for (unsigned int index = 0U; index <= temp.getDegree(); index++) {
        for (unsigned int i = 0U; i <= index; i++) {
            temp.setCoefficientByIndex(index, temp.getCoefficientByIndex(index) + first.getCoefficientByIndex(i) * second.getCoefficientByIndex(index - i));
        }
    }
    return temp;
}

#endif