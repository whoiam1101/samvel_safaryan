#include <iostream>
#include <fstream>

#include "lib/all.h"

using namespace std;

void _showHelp();

int main() {
    while (true) {
        string command;
        cout << "Enter command(help, exit, add) -> ";
        cin >> command;

        if (_isEqual(command, "help")) {
            _showHelp();
        } else if (_isEqual(command, "exit")) {
            break;
        } else if (_isEqual(command, "add")) {
            Hotel new_hotel;

            cout << " Enter hotel name -> ";
            cin >> new_hotel.hotel_name;

            cout << " Enter country name -> ";
            cin >> new_hotel.country_name;

            cout << " Enter city name -> ";
            cin >> new_hotel.city_name;

            cout << " Enter count of flats -> ";
            cin >> new_hotel.count_of_flats;

            if (new_hotel.isExist()) {
                cout << new_hotel.hotel_name << " is exist!\n";
                continue;
            }

            ifstream rhotels_count("hotels_count.txt");
            rhotels_count >> new_hotel.hotel_id;
            rhotels_count.close();

            new_hotel.hotel_id++;

            ofstream whotels_count("hotels_count.txt");
            whotels_count << new_hotel.hotel_id << endl;
            whotels_count.close();

            new_hotel.write();

            InHotel* inhotel = new InHotel[new_hotel.count_of_flats];
            for (unsigned int i = 1; i <= new_hotel.count_of_flats; i++) {
                inhotel[i - 1].hotel_id = new_hotel.hotel_id;
                inhotel[i - 1].room_id  = i;
                cout << " Enter the price of flat " << i << endl;
                cin >> inhotel[i - 1].price;
                cout << " Enter the count of rooms in flat " << i << endl;
                cin >> inhotel[i - 1].count_of_rooms;
                inhotel[i - 1].is_occupied = false;

                inhotel[i - 1].write();
            }

        } else {
            cout << "'" << command << "' not support!\n";
        }
    }
    return 0;
}

void _showHelp() {
    cout << "   help --- show all commands with information\n";
    cout << "   exit --- exit this console application\n";
    cout << "   add  --- add hotel with information for hotel\n";
}