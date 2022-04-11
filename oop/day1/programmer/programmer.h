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