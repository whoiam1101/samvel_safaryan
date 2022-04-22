#ifndef PROGRAMMER_PROGRAMMER_H
#define PROGRAMMER_PROGRAMMER_H

#include "enums/myenums.h"
#include "homosapiens/homosapiens.h"

using namespace Programming;
using namespace TextEditors;
using namespace ProgrammingLanguageParadigm;

class Programmer : HomoSapiens {
private:
    ProgrammerType  _type;
    ProgrammerLevel _level;

    Company _company;
    unsigned int _salary;

public:
    Programmer() {
        _level = ProgrammerLevel::LEARNER;
        _salary = 0U;
    }

    Programmer(
        ProgrammerType type,
        ProgrammerLevel level,
        Company company,
        unsigned int salary
    ) {
        _type    = type;
        _level   = level;
        _company = company;
        _salary  = salary;
    }

    void setProgrammerType(ProgrammerType);
    void setSalary(unsigned int);

    bool setProgrammerLevel(ProgrammerLevel);
    bool setWorkPlace(Company);

    const char* getProgrammerType()  const;
    const char* getProgrammerLevel() const;
    const char* getWorkPlace()       const;

    unsigned int getSalary() const;
};

#endif