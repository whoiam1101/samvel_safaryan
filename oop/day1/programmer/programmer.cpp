#include "programmer.h"

const char* company[] = {
    "MICROSOFT",
    "ALPHABET",
    "APPLE",
    "SAMSUNG",
    "ORACLE"
};

const char* programmer_level[] = {
    "LEARNER",
    "JUNIOR",
    "MIDDLE",
    "SENIOR",
    "LEAD"
};

const char* programmer_type[] = {
    "FRONTEND DEVELOPER",
    "BACKEND DEVELOPER",
    "FULLSTACK DEVELOPER",
    "DEVOPS ENGINNER",
    "DATA SCIENTIST",
    "AI DEVELOPER"
};

void Programmer::setProgrammerType(ProgrammerType type) {
    _type = type;
}

bool Programmer::setProgrammerLevel(ProgrammerLevel level) {
    if (level > _level) {
        _level = level;
        return true;
    }
    return false;
}

bool Programmer::setWorkPlace(Company company) {
    if (company != _company) {
        _company = company;
        return true;
    }
    return false;
}

void Programmer::setSalary(unsigned int salary) {
    _salary = salary;
}

const char* Programmer::getProgrammerType() const {
    return programmer_type[_type];
}

const char* Programmer::getProgrammerLevel() const {
    return programmer_level[_level];
}

const char* Programmer::getWorkPlace() const {
    return company[_company];
}

unsigned int Programmer::getSalary() const {
    return _salary;
}