#ifndef HOMOSAPIENS_HOMOSAPIENS_H
#define HOMOSAPIENS_HOMOSAPIENS_H

#include "enums/myenums.h"
#include "human/human.h"

using HumanEnums::Religion;
using HumanEnums::Race;

class HomoSapiens : Human {
private:
    char* _address;
    char* _full_name;

    Religion _religion;
    Race _race;

public:
    void work() override;
    void dance() override;

    char* getAddress() const;
    char* getFullName() const;

    Religion getReligion() const;
    Race getRace() const;

    void setReligion(Religion);
    void setAddress(char*);
};

#endif