#include <iostream>
#include <vector>

using namespace std;

struct point_t {
	double x;
	double y;

	point_t() : x(0.0), y(0.0) {}
	point_t(double x, double y) : x(x), y(y) {}
};

class Graphic {
public:
	virtual void moveObject(const point_t&) = 0;
	virtual void drawObject() const = 0;
};

class Dot : public Graphic {
private:
	point_t _point;

public:
	Dot() {}
	Dot(const point_t& point) : _point(point) {}

	~Dot() {}

	void setPoint(const point_t& point) { _point = point; }

	double x() const { return _point.x; }
	double y() const { return _point.y; }

	void moveObject(const point_t& delta) override {
		_point.x += delta.x;
		_point.y += delta.y;
	}

	void drawObject() const override { cout << "Dot -> x := " << x() << ", y := " << y() << endl; }
};

class Circle : public Dot {
private:
	double _radius;

public:
	Circle() : _radius(0.0) {}
	Circle(const point_t& centre, double radius) {
		setPoint(centre);
		_radius = radius;
	}

	void drawObject() const override { cout << "Circle -> radius := " << _radius << ", x := " << x() << ", y := " << y() << endl; }
};

class CompoundGraphic : public Graphic {
private:
	vector<Graphic*> _object;

public:
	CompoundGraphic() {}

	~CompoundGraphic() {}

	void add(Graphic* new_object) { _object.push_back(new_object); }
	void remove(Graphic* object)  {
		for (int i = 0; i < (int) _object.size(); i++) {
			if (_object[i] == object) {
			 	_object.erase(_object.begin() + i);
				break;
			}
		}
	}

	void moveObject(const point_t& delta) override {
		for (int i = 0; i < (int) _object.size(); i++) {
		 	_object[i]->moveObject(delta);
		}
	}

	void drawObject() const override {
	 	for (int i = 0; i < (int) _object.size(); i++) {
	 	 	_object[i]->drawObject();
		}
	}
};

int main() {
	CompoundGraphic* compound_graphic = new CompoundGraphic();

	Graphic* circle = new Circle(point_t(13.0, -13.0), 2.0);
	Graphic* dot    = new Dot(point_t(2.0, 3.0));

	compound_graphic->add(circle);
	compound_graphic->add(dot);

	compound_graphic->drawObject();
	cout << endl;

	compound_graphic->moveObject(point_t(2.0, 3.0));
	compound_graphic->drawObject();
  return 0;
}
