#ifndef INHOTEL_H
#define INHOTEL_H

#include <fstream>
#include <cstring>

using namespace std;

#include "hotel.h"
#include "date.h"
#include "substring.h"

struct InHotel {
    unsigned int hotel_id;
    unsigned int room_id;

    unsigned int price;
    unsigned int count_of_rooms;

    bool is_occupied;

    void write() const {
        string file_dir = "InHotel/" + to_string(hotel_id) + ".txt";
        ofstream fout;
        fout.open(file_dir.c_str(), ios::app);
        fout << hotel_id << ", " << room_id << ", " << price << ", " << count_of_rooms << ", " << is_occupied << endl;
    }
};

#endif