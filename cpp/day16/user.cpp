#include <iostream>

#include "lib/all.h"

using namespace std;

void _showHelp();

int main() {
    while (true) {
        string command;
        cout << "Enter the one of this commands: tobook, help, exit -> ";
        cin >> command;

        if (_isEqual(command, "tobook")) {
            Hotel wanted_hotel;

            cout << "Enter country name -> ";
            cin >> wanted_hotel.country_name;

            cout << "Enter city name -> ";
            cin >> wanted_hotel.city_name;

            cout << "Enter hotel name -> ";
            cin >> wanted_hotel.hotel_name;

            if (wanted_hotel.isExist()) {
                bool isoccupiedroom[wanted_hotel.count_of_flats] = {};
                int price[wanted_hotel.count_of_flats] = {};

                string inhotel_file = "InHotel/" + to_string(wanted_hotel.hotel_id) + ".txt";
                ifstream fin(inhotel_file.c_str());
                string inhotel;
                while (getline(fin, inhotel)) {
                    int pos = 0;
                    int ignore         = atoi(_subLine(inhotel, pos).c_str());
                    int room_id        = atoi(_subLine(inhotel, pos).c_str());
                    price[room_id - 1] = atoi(_subLine(inhotel, pos).c_str());
                    int count_of_rooms = atoi(_subLine(inhotel, pos).c_str());
                    int isoccupied     = atoi(_subLine(inhotel, pos).c_str());

                    if (isoccupied) {
                        isoccupiedroom[room_id - 1] = true;
                        continue;
                    }

                    cout << " The " << room_id << " is free (price = " << price[room_id - 1] << ", count of rooms = " << count_of_rooms << ")\n";
                }

                fin.close();

                int room_id;
                do {
                    cout << "What room do you want?";
                    cin >> room_id;
                } while (isoccupiedroom[room_id - 1]);

                Date start_date;
                Date end_date;

                cout << " Enter start date for book -> ";
                start_date.setDate();

                cout << " Enter end date for book -> ";
                end_date.setDate();

                cout << " You will be pay " << price[room_id - 1] * (end_date.mm - start_date.mm) << endl;

                string file_name = "HotelInfo/" + to_string(wanted_hotel.hotel_id) + "." + to_string(room_id) + ".txt";
                ofstream fout;
                fout.open(file_name.c_str(), ios::app);
                fout << wanted_hotel.hotel_id << ", " << room_id + 1 << ", " << start_date.getDate() << ", " << end_date.getDate() << endl;
                fout.close();
            } else {
                cout << "You searched hotel doesn't exist in my database\n";
            }
        } else if (_isEqual(command, "exit")) {
            break;
        } else if (_isEqual(command, "help")) {
            _showHelp();
        } else {
            cout << "\'" << command << "\' not support\n";
        }
    }
    return 0;
}

void _showHelp() {
    cout << "   help ----- show all commands with information\n";
    cout << "   exit ----- exit this console application\n";
    cout << "   tobook --- to book hotel for you\n";
}