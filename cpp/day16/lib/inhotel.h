#ifndef INHOTEL_H
#define INHOTEL_H

#include <fstream>

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
};

#endif