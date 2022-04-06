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
            InHotel in_new_hotel;

            cout << " Enter hotel name -> ";
            getline(cin, new_hotel.hotel_name);

            cout << " Enter country name -> ";
            getline(cin, new_hotel.country_name);

            cout << " Enter city name -> ";
            getline(cin, new_hotel.city_name);

            if (new_hotel.isExist()) {
                cout << new_hotel.hotel_name << " is exist!\n";
                continue;
            }

            ifstream rhotels_count("hotels_count.txt");
            rhotels_count >> new_hotel.hotel_id;
            rhotels_count.close();

            new_hotel.hotel_id++;

            ofstream whotels_count("hotel_count.txt");
            whotels_count << new_hotel.hotel_id << endl;
            whotels_count.close();

            new_hotel.write();

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