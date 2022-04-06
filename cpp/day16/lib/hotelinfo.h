#ifndef HOTEL_INFO_H
#define HOTEL_INFO_H

#include "date.h"

struct HotelInfo {
    unsigned int hotel_id;
    unsigned int room_id;

    Date start_date;
    Date end_date;
};

#endif