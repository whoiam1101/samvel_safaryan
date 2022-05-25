#include <iostream>
#include <cmath>

using namespace std;

class RoundPeg {
private:
  double _radius;

public:
  RoundPeg() : _radius(0.0) {}
  RoundPeg(double radius) : _radius(radius) {}

  ~RoundPeg() {}

  virtual double getRadius() const { return _radius; }
};

class SquarePeg {
private:
  double _length;

public:
  SquarePeg() : _length(0.0) {}
  SquarePeg(double length) : _length(length) {}

  ~SquarePeg() {}

  double getLength() const { return _length; }
};

class SquarePegAdapter : public RoundPeg {
private:
  SquarePeg* _square_peg;

public:
  SquarePegAdapter() : _square_peg(nullptr) {}
  SquarePegAdapter(SquarePeg* square_peg) : _square_peg(square_peg) {}

  ~SquarePegAdapter() {
    delete _square_peg;
    _square_peg = nullptr;
  }

  double getRadius() const override { return _square_peg->getLength() * sqrt(2.0) / 2.0; }
};

class RoundHole {
private:
  double _radius;

public:
  RoundHole() : _radius(0.0) {}
  RoundHole(double radius) : _radius(radius) {}

  ~RoundHole() {}

  double getRadius() const { return _radius; }
  bool isFits(RoundPeg* round_peg) const { return getRadius() >= round_peg->getRadius(); }
};

int main() {
  RoundHole* round_hole  = new RoundHole(5.0);

  RoundPeg*  round_peg   = new RoundPeg(4.0);
  cout << round_hole->isFits(round_peg) << endl;

  SquarePeg* square_peg1 = new SquarePeg(8.0);
  SquarePeg* square_peg2 = new SquarePeg(5.0);
  SquarePegAdapter* adapter_1 = new SquarePegAdapter(square_peg1);
  SquarePegAdapter* adapter_2 = new SquarePegAdapter(square_peg2);
  cout << round_hole->isFits(adapter_1) << endl;
  cout << round_hole->isFits(adapter_2) << endl;
  return 0;
}