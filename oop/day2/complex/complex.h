#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

class Complex {
private:
    double _real_part;
    double _imaginary_part;

    double _argument;
    double _norm;

public:
    Complex() {
        _real_part      = 0.0;
        _imaginary_part = 0.0;
        _argument = 0.0;
        _norm     = 0.0;
    }

    Complex(double real, double imaginary) {
        setRealPart(real);
        setImaginaryPart(imaginary);
        setArgument();
        setNorm();
    }

    void setRealPart(double);
    void setImaginaryPart(double);

    void setRealPart();
    void setImaginaryPart();

    void setArgument(double);
    void setNorm(double);

    void setArgument();
    void setNorm();

    double getRealPart()      const;
    double getImaginaryPart() const;

    double getArgument() const;
    double getNorm()     const;

    double getSqrNorm() const;

    Complex conjugate() const;
    Complex pow(int) const;
};

Complex operator + (const Complex a, const Complex b) {
    return Complex(a.getRealPart() + b.getRealPart(), a.getImaginaryPart() + b.getImaginaryPart());
}

Complex operator - (const Complex a, const Complex b) {
    return Complex(a.getRealPart() - b.getRealPart(), a.getImaginaryPart() - b.getImaginaryPart());
}

Complex operator * (const Complex a, const Complex b) {
    return Complex(
        a.getRealPart() * b.getRealPart() - a.getImaginaryPart() * b.getImaginaryPart(),
        a.getRealPart() * b.getImaginaryPart() + a.getImaginaryPart() * b.getRealPart()
    );
}

Complex operator / (const Complex a, const double b) {
    return Complex(a.getRealPart() / b, a.getImaginaryPart() / b);
}

Complex operator / (const Complex a, const Complex b) {
    return a * b.conjugate() / b.getSqrNorm();
}

#endif