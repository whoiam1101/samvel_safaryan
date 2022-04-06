#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <cassert>
#include <fstream>

#include "substring.h"

using namespace std;

struct Hotel {
    unsigned int hotel_id;

    string hotel_name;
    string country_name;
    string city_name;

    unsigned int count_of_flats;

    void write() const {
        ofstream fout("hotels.txt", ios::app);
        fout << hotel_id << ", "
            << hotel_name << ", "
            << country_name << ", "
            << city_name << ", "
            << count_of_flats << endl;
        fout.close();
    }

    bool isExist() {
        ifstream fin("hotels.txt");
        string information;
        while (getline(fin, information)) {
            int pos = 0;
            unsigned int ignore = (unsigned int) atoi(_subLine(information, pos).c_str());

            if (
                _isEqual(_subLine(information, pos), hotel_name) &&
                _isEqual(_subLine(information, pos), country_name) &&
                _isEqual(_subLine(information, pos), city_name)
            ) {
                fin.close();
                return true;
            }
        }

        fin.close();

        return false;
    }
};

#endif