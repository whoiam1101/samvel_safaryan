#ifndef INHOTEL_H
#define INHOTEL_H

#include <fstream>

using namespace std;

#include "hotel.h"
#include "date.h"
#include "substring.h"

struct InHotel {
    unsigned int countOfRooms;

    bool *isOccupied;

    unsigned int *price;

    Date *startTime;
    Date *endTime;

    InHotel() {
        countOfRooms = 0;
    }

    InHotel(Hotel hotel) {
        countOfRooms = hotel.countOfRooms;

        isOccupied = new bool[countOfRooms];

        price = new unsigned int[countOfRooms];

        for (int i = 0; i < countOfRooms; i++) {
            isOccupied[i] = false;
            price[i] = 0;
        }

        startTime = new Date[countOfRooms];
        endTime   = new Date[countOfRooms];

        string date_file = "Hotels/" + hotel.hotelName + ".txt";
        ifstream fin(date_file.c_str());

        for (int i = 0; i < countOfRooms; i++) {
            string sentence;
            getline(fin, sentence);
            int pos = 0;
            while (sentence[pos] != '\0') {
                price[i] = (unsigned int) atoi(_subLine(sentence, pos).c_str());
                isOccupied[i] = atoi(_subLine(sentence, pos).c_str());
                startTime[i].setDate(_subLine(sentence, pos));
                endTime[i].setDate(_subLine(sentence, pos));
                pos++;
            }
        }

        fin.close();
    }
};

#endif