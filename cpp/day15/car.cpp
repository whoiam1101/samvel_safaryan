#include <iostream>
#include <cstring>
#include <fstream>
#include <cassert>

using namespace std;

string _subLine(string, int&);
void _ignoreSpace(string, int&);

int _carsCount();

void _showHelp();

bool _isEqual(string, string);

struct Car {
    string name;
    string gearbox;
    int minimumprice;
    int maximumprice;
    int mileage;
    int enginecapacity;

    Car() {
        name           = "";
        gearbox        = "";
        minimumprice   = 0;
        maximumprice   = 0;
        mileage        = 0;
        enginecapacity = 0;
    }

    Car(string _name, int _minimumprice, int _maximumprice, int _milage, int _enginecapacity, string _gearbox) {
        name           = _name;
        minimumprice   = _minimumprice;
        maximumprice   = _maximumprice;
        mileage        = _milage;
        enginecapacity = _enginecapacity;
        gearbox        = _gearbox;
    }

    void showInformation() const {
        cout << "   Name            : " << name << endl;
        cout << "   Minimum price   : " << minimumprice << endl;
        cout << "   Maximum price   : " << maximumprice << endl;
        cout << "   Mileage         : " << mileage << endl;
        cout << "   Engine capacity : " << enginecapacity << endl;
    }

    void getInformation(string sentence) {
        int pos = 0;
        while (sentence[pos] != '\0') {
            name           = _subLine(sentence, pos);
            minimumprice   = atoi(_subLine(sentence, pos).c_str());
            maximumprice   = atoi(_subLine(sentence, pos).c_str());
            mileage        = atoi(_subLine(sentence, pos).c_str());
            enginecapacity = atoi(_subLine(sentence, pos).c_str());
            gearbox        = _subLine(sentence, pos);
        }
    }
};

int main() {
    const int COUNT_OF_CARS = _carsCount();
    Car car[COUNT_OF_CARS];

    ifstream fin("carstable.txt");
    string information;
    int iterator = 0;
    while (getline(fin, information)) {
        car[iterator].getInformation(information);
        iterator++;
    }
    fin.close();

    while (true) {
        string entered_command;
        cout << "Commands : help, exit, showall, show" << endl;
        cout << "Enter the command -> ";
        cin >> entered_command;

        if (_isEqual(entered_command, "help")) {
            _showHelp();
        } else if (_isEqual(entered_command, "exit")) {
            break;
        } else if (_isEqual(entered_command, "showall")) {
            for (int i = 1; i <= COUNT_OF_CARS; i++) {
                cout << "Car " << i << " : " << endl;
                car[i - 1].showInformation();
            }
        } else if (_isEqual(entered_command, "show")) {
            string filters;
            cout << "Filters\n";
            cout << " 1 - car name"        << endl;
            cout << " 2 - minimum price"   << endl;
            cout << " 3 - maximum price"   << endl;
            cout << " 4 - mileage"         << endl;
            cout << " 5 - engine capacity" << endl;
            cout << " 6 - gearbox"         << endl;
            cout << "Enter filters -> ";
            cin >> filters;

            bool is_filter_used[6] = {};
            for (char c : filters) {
                if ('1' <= c && c <= '6') {
                    is_filter_used[c - '1'] = true;
                }
            }

            bool does_it_fit[COUNT_OF_CARS];
            for (bool& value : does_it_fit) {
                value = true;
            }

            if (is_filter_used[0]) {
                string name;
                cout << "Print car name -> ";
                cin >> name;

                for (int i = 0; i < COUNT_OF_CARS; i++) {
                    if (car[i].name != name) {
                        does_it_fit[i] = false;
                    }
                }
            }

            if (is_filter_used[1]) {
                int minimumprice;
                cout << "Print minimum price for car -> ";
                cin >> minimumprice;

                for (int i = 0; i < COUNT_OF_CARS; i++) {
                    if (car[i].maximumprice < minimumprice) {
                        does_it_fit[i] = false;
                    }
                }
            }

            if (is_filter_used[2]) {
                int maximumprice;
                cout << "Print maximum price for car -> ";
                cin >> maximumprice;

                for (int i = 0; i < COUNT_OF_CARS; i++) {
                    if (car[i].minimumprice > maximumprice) {
                        does_it_fit[i] = false;
                    }
                }
            }

            if (is_filter_used[3]) {
                int mileage;
                cout << "Print mileage for car -> ";
                cin >> mileage;

                for (int i = 0; i < COUNT_OF_CARS; i++) {
                    if (car[i].mileage != mileage) {
                        does_it_fit[i] = false;
                    }
                }
            }

            if (is_filter_used[4]) {
                int enginecapacity;
                cout << "Print engine capacity -> ";
                cin >> enginecapacity;

                for (int i = 0; i < COUNT_OF_CARS; i++) {
                    if (car[i].enginecapacity != enginecapacity) {
                        does_it_fit[i] = false;
                    }
                }
            }

            if (is_filter_used[5]) {
                string gearbox;
                cout << "Print gearbox type(automatic or mechanic) -> ";
                cin >> gearbox;

                for (int i = 0; i < COUNT_OF_CARS; i++) {
                    if (car[i].gearbox != gearbox) {
                        does_it_fit[i] = false;
                    }
                }
            }

            for (int i = 0; i < COUNT_OF_CARS; i++) {
                if (does_it_fit[i]) {
                    car[i].showInformation();
                    cout << endl;
                }
            }
        } else {
            cout << "Your entered command does not support!" << endl;
        }
    }

    return 0;
}

int _carsCount() {
    ifstream fin("carstable.txt");
    assert(("'carstable.txt' file not found!", fin.is_open()));
    int result = 0;
    string _;
    while (getline(fin, _)) {
        result++;
    }
    fin.close();
    return result;
}

string _subLine(string line, int& pos) {
    string result = "";
    while (line[pos] != '\0' && line[pos] != ',') {
        result += line[pos];
        pos++;
    }
    pos++;
    _ignoreSpace(line, pos);

    return result;
}

void _ignoreSpace(string line, int& pos) {
    while (line[pos] == ' ') {
        pos++;
    }
}

void _showHelp() {
    cout << " help    -> show help information for user"     << endl;
    cout << " exit    -> exit this console application"      << endl;
    cout << " showall -> show information for all cars"      << endl;
    cout << " show    -> show information for car by filter or filters" << endl;
}

bool _isEqual(string a, string b) {
    return strcmp(a.c_str(), b.c_str()) == 0;
}