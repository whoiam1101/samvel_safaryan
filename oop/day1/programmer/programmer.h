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
        ProgrammerType _new_type,
        ProgrammerLevel _new_level,
        Company _new_company,
        unsigned int _new_salary
    ) {
        _type    = _new_type;
        _level   = _new_level;
        _company = _new_company;
        _salary  = _new_salary;
    }

    void setProgrammerType(ProgrammerType);
    void setSalary(unsigned int);

    bool setProgrammerLevel(ProgrammerLevel);
    bool setWorkPlace(Company);

    char* getProgrammerType()  const;
    char* getProgrammerLevel() const;
    char* getWorkPlace()       const;

    unsigned int getSalary() const;
};

#endif