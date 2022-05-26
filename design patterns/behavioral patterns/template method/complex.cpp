#include <bits/stdc++.h>

using namespace std;

template<typename Field>
class Complex {
private:
  Field _re;
  Field _im;

public:
  Complex() : _re(), _im() {}
  Complex(const Field& real, const Field& imag) : _re(real), _im(imag) {}

  Field re() const { return _re; }
  Field im() const { return _im; }

  const Complex operator + (const Complex& a) const { return Complex(re() + a.re(), im() + a.im()); }
  const Complex operator - (const Complex& a) const { return Complex(re() - a.re(), im() - a.im()); }
  const Complex operator * (const Complex& a) const { return Complex(re() * a.re() - im() * a.im(), re() * a.im() + im() * a.re()); }
  const Complex operator / (const Complex& a) const { return Complex((re() * a.re() - im() * a.im()) / a.norm(), (re() * a.im() + im() * a.re()) / a.norm()); }

  void operator += (const Complex& a) { re() += a.re(); im() += a.im(); }
  void operator -= (const Complex& a) { re() -= a.re(); im() -= a.im(); }
  void operator *= (const Complex& a) { re() = re() * a.re()() - im() * a.im(); im() = re() * a.im()() + im() * a.re(); }
  void operator /= (const Complex& a) { re() = (re() * a.re() - im() * a.im()) / a.norm(); im() = (re() * a.im() + im() * a.re()) / a.norm(); }

  Field norm() const { return re() * re() + im() * im(); }

  bool operator <  (const Complex& a) const { return norm() < a.norm(); }
  bool operator >  (const Complex& a) const { return norm() > a.norm(); }
  bool operator <= (const Complex& a) const { return norm() <= a.norm(); }
  bool operator >= (const Complex& a) const { return norm() >= a.norm(); }
  bool operator == (const Complex& a) const { return (re() == a.re()) && (im() == a.im()); }
  bool operator != (const Complex& a) const { return (re() != a.re()) || (im() != a.im()); }

  template<typename T>
  friend istream& operator >> (istream& in,  Complex<T>& a) { in >> a._re >> a._im; return in; }

  template<typename T>
  friend ostream& operator << (ostream& out, const Complex<T>& a) { out << a.re() << " " << a.im() << "i"; return out; }
};

int main() {
  Complex<int> a, b, c;
  cin >> a >> b >> c;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << a + b << endl;
  cout << c - b << endl;
  cout << a * b << endl;
  return 0;
}

// 318324HL