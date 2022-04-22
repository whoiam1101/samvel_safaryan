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
    HomoSapiens() {
        _address   = "";
        _full_name = "";

        _religion = Religion::CHRISTIANITY;
        _race = Race::AUSTRALOID;
    }

    HomoSapiens(
        char* address,
        char* full_name,
        Religion religion,
        Race race
    ) {
        _address   = address;
        _full_name = full_name;

        _religion = religion;
        _race = race;
    }

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