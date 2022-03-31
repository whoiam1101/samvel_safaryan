#ifndef DATE_H
#define DATE_H

#include <iostream>

#include "substring.h"

using namespace std;

struct Date {
    unsigned int dd;
    unsigned int mm;
    unsigned int yyyy;

    Date() {
        dd   = 0U;
        mm   = 0U;
        yyyy = 0U;
    }

    Date(
        unsigned int _dd,
        unsigned int _mm,
        unsigned int _yyyy
    ) {
        dd   = _dd;
        mm   = _mm;
        yyyy = _yyyy;
    }

    void setDate(string date) {
        dd   = (unsigned int) atoi(_subString(date, 0, 1).c_str());
        mm   = (unsigned int) atoi(_subString(date, 3, 4).c_str());
        yyyy = (unsigned int) atoi(_subString(date, 6, 9).c_str());
    }

    void setDate() {
        cout << "year: ";
        cin >> yyyy;

        cout << "month: ";
        cin >> mm;

        cout << "day: ";
        cin >> dd;
    }

    string getDate() const {
        return to_string(dd) + "." + to_string(mm) + "." + to_string(yyyy);
    }
};

#endif