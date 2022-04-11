#include "programmer.h"

void Programmer::setProgrammerType(ProgrammerType _new_type) {
    _type = _new_type;
}

bool Programmer::setProgrammerLevel(ProgrammerLevel _new_level) {
    if (_new_level <= _level) {
        return false;
    }

    _level = _new_level;
    return true;
}

bool Programmer::setWorkPlace(Company _new_company) {
    if (_new_company == _company) {
        return false;
    }

    _company = _new_company;
    return true;
}

void Programmer::setSalary(unsigned int _new_salary) {
    _salary = _new_salary;
}

char* Programmer::getProgrammerType() const {
    char* programmer_type[] = {
        "FRONTEND DEVELOPER",
        "BACKEND DEVELOPER",
        "FULLSTACK DEVELOPER",
        "DEVOPS ENGINNER",
        "DATA SCIENTIST",
        "AI DEVELOPER"
    };

    return programmer_type[_type];
}

char* Programmer::getProgrammerLevel() const {
    char* programmer_level[] = {
        "LEARNER",
        "JUNIOR",
        "MIDDLE",
        "SENIOR",
        "LEAD"
    };

    return programmer_level[_level];
}

char* Programmer::getWorkPlace() const {
    char* company[] = {
        "MICROSOFT",
        "ALPHABET",
        "APPLE",
        "SAMSUNG",
        "ORACLE"
    };

    return company[_company];
}

unsigned int Programmer::getSalary() const {
    return _salary;
}