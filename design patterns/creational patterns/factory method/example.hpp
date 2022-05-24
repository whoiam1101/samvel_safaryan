#ifndef __FACTORY_METHOD_EXAMPLE_H__
#define __FACTORY_METHOD_EXAMPLE_H__

class Box {
public:
  virtual ~Box() {}

  virtual unsigned int width()  const = 0;
  virtual unsigned int height() const = 0;
  virtual unsigned int length() const = 0;

  virtual unsigned int capacity() const = 0;
  virtual unsigned int price()    const = 0;
};

class SmallBox : public Box {
public:
  unsigned int width()    const override { return 10U; }
  unsigned int height()   const override { return 10U; }
  unsigned int length()   const override { return 20U; }

  unsigned int capacity() const { return width() * height() * length(); }
  unsigned int price()    const { return capacity(); }
};

class MiddleBox : public Box {
public:
  unsigned int width()    const override { return 20U; }
  unsigned int height()   const override { return 20U; }
  unsigned int length()   const override { return 20U; }

  unsigned int capacity() const { return width() * height() * length(); }
  unsigned int price()    const { return 20U + capacity(); }
};

class BigBox : public Box {
public:
  unsigned int width()    const override { return 30U; }
  unsigned int height()   const override { return 30U; }
  unsigned int length()   const override { return 30U; }

  unsigned int capacity() const { return width() * height() * length(); }
  unsigned int price()    const { return 2U * capacity(); }
};

class BoxCreator {
private:
  static unsigned int _budget;

public:
  virtual ~BoxCreator() {};

  virtual Box* createBox() const = 0;

  unsigned int getBudget() const { return _budget; }

  void toSell() const {
    Box* box = createBox();
    _budget += box->price();
    delete box;
  }
};

class SmallBoxCreator : public BoxCreator {
public:
  Box* createBox() const override { return new SmallBox(); }
};

class MiddleBoxCreator : public BoxCreator {
public:
  Box* createBox() const override { return new MiddleBox(); }
};

class BigBoxCreator : public BoxCreator {
public:
  Box* createBox() const override { return new BigBox(); }
};

void clientCode(const BoxCreator& box_creator) {
  box_creator.toSell();
}

#endif // __FACTORY_METHOD_EXAMPLE_H__