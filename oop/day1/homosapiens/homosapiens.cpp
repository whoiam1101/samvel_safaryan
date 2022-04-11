#include "homosapiens.h"

void HomoSapiens::work() {
    return;
}

void HomoSapiens::dance() {
    return;
}

char* HomoSapiens::getAddress() const {
    return _address;
}

char* HomoSapiens::getFullName() const {
    return _full_name;
}

Religion HomoSapiens::getReligion() const {
    return _religion;
}

Race HomoSapiens::getRace() const {
    return _race;
}

void HomoSapiens::setReligion(Religion _new_religion) {
    _religion = _new_religion;
}

void HomoSapiens::setAddress(char* _new_address) {
    _address = _new_address;
}