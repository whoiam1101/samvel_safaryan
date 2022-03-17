#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

char _lowerCase(char a) {
    const int DIFF = 'a' - 'A';

    if ('A' <= a && a <= 'Z') {
        return a + DIFF;
    }

    return a;
}

string _lowerCase(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = _lowerCase(s[i]);
    }

    return s;
}

char _lastElement(string s) {
    return _lowerCase(s[s.size() - 1]);
}

char _beginElement(string s) {
    return _lowerCase(s[0]);
}

bool _isTrue(string prev, string next) {
    return (_lastElement(prev) == _beginElement(next));
}

int main() {
    ifstream file_reader("world-cities");

    try {
        if (file_reader.good()) {

            bool is_my_move;

            cout << "Who will started(not 0 - I am, 0 - computer): ";
            cin >> is_my_move;

            const int COUNT_OF_CITIES = 23018;
            bool isflag[COUNT_OF_CITIES] = {};

            string prev_city_name = "";

            if (!is_my_move) {
                getline(file_reader, prev_city_name);
            } else {
                do {
                    cout << "\nEnter city name: ";
                    getline(cin, prev_city_name);
                } while (prev_city_name == "");

                int pos = 0;
                string tmp_name;
                bool name_not_found = true;

                while (getline(file_reader, tmp_name)) {
                    if (_lowerCase(prev_city_name) == _lowerCase(tmp_name)) {
                        isflag[pos] = true;
                        name_not_found = false;
                        break;
                    }

                    pos++;
                }

                if (name_not_found) {
                    throw "You lose!!!";
                }
            }

            is_my_move = !is_my_move;

            while (true) {
                cout << "Previous city name is " << prev_city_name << endl;

                string city_name;
                bool name_not_found = true;

                file_reader.close();
                file_reader.open("world-cities");

                if (is_my_move) {
                    cout << "\nEnter city name: ";
                    getline(cin, city_name);

                    int pos = 0;
                    string temp_name;

                    while (getline(file_reader, temp_name)) {
                        if (_lowerCase(city_name) == _lowerCase(temp_name) && _isTrue(prev_city_name, city_name) && !isflag[pos]) {
                            name_not_found = false;
                            isflag[pos] = true;
                            pos++;
                        }
                    }
                } else {
                    int pos = 0;

                    while (getline(file_reader, city_name)) {
                        if (_isTrue(prev_city_name, city_name) && !isflag[pos]) {
                            name_not_found = false;
                            isflag[pos] = true;
                            break;
                        }

                        pos++;
                    }
                }

                if (name_not_found) {
                    throw "You lose!!!";
                }

                prev_city_name = city_name;
                is_my_move = !is_my_move;
            }
        } else {
            throw "world_cities file cannot find!!!\n";
        }

    } catch (const char* message) {
        cout << message << endl;

        file_reader.close();
    }

    return 0;
}
