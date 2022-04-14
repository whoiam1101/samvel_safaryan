#ifndef REALPOLYNOMIAL_REALPOLYNOMIAL_H
#define REALPOLYNOMIAL_REALPOLYNOMIAL_H

#include "../polynomial/polynomial.h"

#include "istream"
#include "ostream"

class RealPolynomial {
private:
    unsigned int _degree;
    double* _coefficient;
    double _lambda;

    void setLambda(double);
    double getLambda() const;

    void refactorDegree();

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

    RealPolynomial(const RealPolynomial& polynom) {
        this->setCoefficients(polynom.getDegree(), polynom.getCoefficients());
    }

    ~RealPolynomial() {
        delete [] _coefficient;
    }

    void setDegree(unsigned int);
    void setCoefficients(unsigned int, double*);
    void setCoefficientByIndex(unsigned int, double);

    unsigned int getDegree() const;

    double* getCoefficients() const;
    double getCoefficientByIndex(unsigned int) const;
    double getValueAtPoint(double) const;

    RealPolynomial pow(unsigned int) const;

    void operator += (const RealPolynomial&);
    void operator -= (const RealPolynomial&);
    void operator *= (const RealPolynomial&);
    void operator *= (const double&);
    void operator  = (const RealPolynomial&);

    friend RealPolynomial operator + (const RealPolynomial&, const RealPolynomial&);
    friend RealPolynomial operator - (const RealPolynomial&, const RealPolynomial&);
    friend RealPolynomial operator * (const RealPolynomial&, const RealPolynomial&);
    friend RealPolynomial operator * (const RealPolynomial&, const double&);
    friend RealPolynomial operator * (const double&, const RealPolynomial&);

    friend std::istream& operator >> (std::istream&, RealPolynomial&);
    friend std::ostream& operator << (std::ostream&, const RealPolynomial&);
};

#endif