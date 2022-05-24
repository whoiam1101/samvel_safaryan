#ifndef __ABSTRACT_FACTORY_EXAMPLE_H__
#define __ABSTRACT_FACTORY_EXAMPLE_H__

#include <iostream>

class Chair {
public:
  virtual ~Chair() {}

  virtual unsigned int numberOfLegs() const = 0;
  virtual unsigned int price()        const = 0;
};

class ArtDecoChair : public Chair {
public:
  unsigned int numberOfLegs() const override { return 8U; }
  unsigned int price()        const override { return 100U; }
};

class VictorianChair : public Chair {
public:
  unsigned int numberOfLegs() const override { return 4U; }
  unsigned int price()        const override { return 200U; }
};

class ModernChair : public Chair {
public:
  unsigned int numberOfLegs() const override { return 2U; }
  unsigned int price()        const override { return 1000U; }
};

class Sofa {
public:
  virtual ~Sofa() {}

  virtual unsigned int capacity() const = 0;
  virtual unsigned int price()    const = 0;
};

class ArtDecoSofa : public Sofa {
public:
  unsigned int capacity() const override { return 4U; }
  unsigned int price()    const override { return 200U; }
};

class VictorianSofa : public Sofa {
public:
  unsigned int capacity() const override { return 5U; }
  unsigned int price()    const override { return 500U; }
};

class ModernSofa : public Sofa {
public:
  unsigned int capacity() const override { return 3U; }
  unsigned int price()    const override { return 2000U; }
};

class CoffeeTable {
public:
  virtual ~CoffeeTable() {}

  virtual unsigned int area()  const = 0;
  virtual unsigned int price() const = 0;
};

class ArtDecoCoffeeTable : public CoffeeTable {
public:
  unsigned int area()  const override { return 2U; }
  unsigned int price() const override { return 50U; }
};

class VictorianCoffeeTable : public CoffeeTable {
public:
  unsigned int area()  const override { return 3U; }
  unsigned int price() const override { return 75U; }
};

class ModernCoffeeTable : public CoffeeTable {
public:
  unsigned int area()  const override { return 3U; }
  unsigned int price() const override { return 200U; }
};

class AbstractFactory {
public:
  virtual ~AbstractFactory() {}

  virtual Chair*       createChair()       const = 0;
  virtual Sofa*        createSofa()        const = 0;
  virtual CoffeeTable* createCoffeeTable() const = 0;
};

class ArtDecoAbstractFactory : public AbstractFactory {
public:
  Chair*       createChair()       const override { return new ArtDecoChair(); }
  Sofa*        createSofa()        const override { return new ArtDecoSofa(); }
  CoffeeTable* createCoffeeTable() const override { return new ArtDecoCoffeeTable(); }
};

class VictorianAbstractFactory : public AbstractFactory {
public:
  Chair*       createChair()       const override { return new VictorianChair(); }
  Sofa*        createSofa()        const override { return new VictorianSofa(); }
  CoffeeTable* createCoffeeTable() const override { return new VictorianCoffeeTable(); }
};

class ModernAbstractFactory : public AbstractFactory {
public:
  Chair*       createChair()       const override { return new ModernChair(); }
  Sofa*        createSofa()        const override { return new ModernSofa(); }
  CoffeeTable* createCoffeeTable() const override { return new ModernCoffeeTable(); }
};

void ClientCode(const AbstractFactory& abstract_fatory) {
  const Chair*       chair        = abstract_fatory.createChair();
  const Sofa*        sofa         = abstract_fatory.createSofa();
  const CoffeeTable* coffee_table = abstract_fatory.createCoffeeTable();

  std::cout << "Chair        price : " << chair->price()        << std::endl;
  std::cout << "Sofa         price : " << sofa->price()         << std::endl;
  std::cout << "Coffee table price : " << coffee_table->price() << std::endl;

  delete chair;
  delete sofa;
  delete coffee_table;
}

#endif // __ABSTRACT_FACTORY_EXAMPLE_H__