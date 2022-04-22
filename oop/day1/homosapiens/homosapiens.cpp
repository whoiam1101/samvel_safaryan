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

void HomoSapiens::setReligion(Religion religion) {
    _religion = religion;
}

void HomoSapiens::setAddress(char* address) {
    _address = address;
}