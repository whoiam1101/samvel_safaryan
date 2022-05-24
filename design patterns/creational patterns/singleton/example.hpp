#ifndef __SINGLETON_EXAMPLE_H__
#define __SINGLETON_EXAMPLE_H__

class Russia {
private:
  unsigned int _area;

  static Russia* _russia;
  Russia() : _area(17125191U) {}

public:
  Russia(Russia&) = delete;
  void operator = (const Russia&) = delete;

  static Russia* getInstance();

  void addArea(unsigned int darea);
  unsigned int getArea() const;
};

Russia* Russia::getInstance() {
  if (_russia == nullptr) {
    _russia = new Russia();
  }
  return _russia;
}

void Russia::addArea(unsigned int darea) {
  _area += darea;
}

unsigned int Russia::getArea() const {
  return _area;
}

#endif // __SINGLETON_EXAMPLE_H__