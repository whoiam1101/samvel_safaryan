#include <iostream>

using namespace std;

enum EnumCompanies {
  FACEBOOK = 0,
  TELEGRAM,
  TWITTER
};

class Facebook;
class Telegram;
class Twitter;

class Visitor {
public:
  virtual ~Visitor() {}

  virtual void visit(Facebook&) = 0;
  virtual void visit(Telegram&) = 0;
  virtual void visit(Twitter&)  = 0;
};

class Company {
public:
  virtual ~Company() {}

  virtual void accept(Visitor&) = 0;
};

class Facebook : public Company {
public:
  void accept(Visitor& visitor) override { visitor.visit(*this); }
};

class Telegram : public Company {
public:
  void accept(Visitor& telegram) override { telegram.visit(*this); }
};

class Twitter : public Company {
public:
  void accept(Visitor& twitter) override { twitter.visit(*this); }
};

class HumanVisitor : public Visitor {
private:
  EnumCompanies _company;

public:
  void visit(Facebook& facebook) override { _company = EnumCompanies::FACEBOOK; }
  void visit(Telegram& telegram) override { _company = EnumCompanies::TELEGRAM; }
  void visit(Twitter&  twitter)  override { _company = EnumCompanies::TWITTER; }

  void whatCompany() const {
    switch (_company) {
    case EnumCompanies::FACEBOOK: cout << "I'm in facebook now!\n"; break;
    case EnumCompanies::TELEGRAM: cout << "I'm in telegram now!\n"; break;
    case EnumCompanies::TWITTER:  cout << "I'm in twitter  now!\n";   break;
    }
  }
};

int main() {
  Company* facebook = new Facebook();
  Company* telegram = new Telegram();
  Company* twitter  = new Twitter();
  HumanVisitor human_visitor;

  facebook->accept(human_visitor);
  human_visitor.whatCompany();

  telegram->accept(human_visitor);
  human_visitor.whatCompany();

  twitter->accept(human_visitor);
  human_visitor.whatCompany();

  return 0;
}