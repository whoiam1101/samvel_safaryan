#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <cassert>

#include "substring.h"

using namespace std;

struct Hotel {
    string hotelName;
    string countryName;
    string address;

    unsigned int stars;
    unsigned int countOfRooms;

    Hotel() {
        hotelName   = "";
        countryName = "";
        address     = "";

        stars        = 0;
        countOfRooms = 0;
    }

    Hotel(
        string _hotelName,
        string _countryName,
        string _address,
        unsigned int _stars
    ) {
        hotelName   = _hotelName;
        countryName = _countryName;
        address     = _address;

        stars        = _stars;
        countOfRooms = _roomsCount(hotelName);
    }

    void setInformation(string information) {
        int pos = 0;
        while (information[pos] != '\0') {
            hotelName   = _subLine(information, pos);
            countryName = _subLine(information, pos);
            address     = _subLine(information, pos);

            stars = (unsigned int) atoi(_subLine(information, pos).c_str());
        }
    }
};

#endif