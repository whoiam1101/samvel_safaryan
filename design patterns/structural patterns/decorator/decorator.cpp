#include <iostream>

using namespace std;

class SuperHero {
public:
  ~SuperHero() {}

  virtual string getDescription() const = 0;
};

class BaseSuperHero : public SuperHero {
private:
  unsigned int _power_level;
  unsigned int _agility_level;
  unsigned int _intelligence_level;
  unsigned int _survivability_level;

public:
  BaseSuperHero() :
    _power_level(1U),
    _agility_level(1U),
    _intelligence_level(120U),
    _survivability_level(1U) {}

  BaseSuperHero(
    unsigned int power_level,
    unsigned int agility_level,
    unsigned int intelligence_level,
    unsigned int survivability_level
  ) {
    setPowerLevel(power_level);
    setAgilityLevel(agility_level);
    setIntelligenceLevel(intelligence_level);
    setSurvivabilityLevel(survivability_level);
  }

  ~BaseSuperHero() {}

  void setPowerLevel(unsigned int power_level)                 { _power_level = power_level; }
  void setAgilityLevel(unsigned int agility_level)             { _agility_level = agility_level; }
  void setIntelligenceLevel(unsigned int intelligence_level)   { _intelligence_level = intelligence_level; }
  void setSurvivabilityLevel(unsigned int survivability_level) { _survivability_level = survivability_level; }

  unsigned int getPowerLevel()         const { return _power_level; }
  unsigned int getAgilityLevel()       const { return _agility_level; }
  unsigned int getIntelligenceLevel()  const { return _intelligence_level; }
  unsigned int getSurvivabilityLevel() const { return _survivability_level; }

  string getDescription() const override {
    return
      "Power level         := " + to_string(getPowerLevel())         + "\n" +
      "Agility level       := " + to_string(getAgilityLevel())       + "\n" +
      "Intelligence level  := " + to_string(getIntelligenceLevel())  + "\n" +
      "Survivability level := " + to_string(getSurvivabilityLevel()) + "\n";
  }
};

class SuperHeroDecorator : public SuperHero {
protected:
  SuperHero* _super_hero;

public:
  SuperHeroDecorator(SuperHero* super_hero) : _super_hero(super_hero) {}

  string getDescription() const { return _super_hero->getDescription(); }
};

class BlackSuperHero : public SuperHeroDecorator {
public:
  BlackSuperHero(SuperHero* super_hero) : SuperHeroDecorator(super_hero) {}

  string getDescription() const {
    return
      "Super hero color is black\n" +
      SuperHeroDecorator::getDescription();
  }
};

class GreenSuperHero : public SuperHeroDecorator {
public:
  GreenSuperHero(SuperHero* super_hero) : SuperHeroDecorator(super_hero) {}

  string getDescription() const {
    return
      "Super hero color is green\nShe or he is very strong\n" +
      SuperHeroDecorator::getDescription();
  }
};

int main() {
  SuperHero* hulk   = new GreenSuperHero(new BaseSuperHero(88U, 3U, 70U, 100U));
  SuperHero* batman = new BlackSuperHero(new BaseSuperHero(10U, 80U, 250U, 60U));
  cout << hulk->getDescription() << endl;
  cout << endl;
  cout << batman->getDescription() << endl;
  return 0;
}