#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>

#include "lib/substring.h"
#include "lib/hotel.h"
#include "lib/inhotel.h"

using namespace std;

void _showHelp();

int _countOfHotels();

int main() {
    ifstream fin("hotels.txt");

    const int COUNT_OF_HOTELS = _countOfHotels();

    Hotel* hotel = new Hotel[COUNT_OF_HOTELS];
    string information;
    int iterator = 0;

    while (getline(fin, information)) {
        hotel[iterator].setInformation(information);
    }

    fin.close();

    InHotel* inhotel = new InHotel[COUNT_OF_HOTELS];
    for (int i = 0; i < COUNT_OF_HOTELS; i++) {
        inhotel[i] = InHotel(hotel[i]);
    }

    while (true) {
        string command;
        cout << "Enter the command(help, exit, tobook) -> ";
        cin >> command;

        if (_isEqual(command, "help")) {
            _showHelp();
        } else if (_isEqual(command, "exit")) {
            break;
        } else if (_isEqual(command, "tobook")) {

        } else {
            cout << "Your inputed command hasn't supported" << endl;
        }
    }

    return 0;
}

int _countOfHotels() {
    ifstream fin("hotels.txt");
    assert(("hotels.txt file not found!", fin.is_open()));

    int countOfLines = 0;
    string _;
    while (getline(fin, _)) {
        countOfLines++;
    }

    fin.close();

    return countOfLines;
}

void _showHelp() {
    cout << "   help - show all commands for user" << endl;
    cout << "   exit - exit this console application" << endl;
    cout << "   tobook - to book hotel" << endl;
}