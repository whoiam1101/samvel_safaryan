#include <iostream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <cstring>

using namespace std;

char _difference(long long, long long);

int _lineCount();

string _convertNumber(long long);
string _subLine(string, int&);

void _ignoreSpace(string, int&);

struct Country {
    string name;
    string capital;
    string domain;
    long long gdb;
    int phonecode;
    int population;
    int area;

    Country() {
        name = "";
        capital = "";
        domain = "";
        gdb = 0LL;
        phonecode = 0;
        population = 0;
        area = 0;
    }

    Country(string name, string capital, string domain, int population, int area, long long gdb, int phonecode) {
        name       = name;
        capital    = capital;
        domain     = domain;
        population = population;
        area       = area;
        gdb        = gdb;
        phonecode  = phonecode;
    }

    void getInformation() const {
        cout << "Output: Country    - " << name << endl;
        cout << "        Capital    - " << capital << endl;
        cout << "        Domain     - " << domain << endl;
        cout << "        Population - " << population << endl;
        cout << "        Area       - " << area << endl;
        cout << "        GDB        - " << gdb << endl;
        cout << "        Phone Code - +" << phonecode << endl;
    }
};

int main(int argc, char* argv[]) {
    assert(("Please add neither 'search' or 'compare' argument for correctly working this programm",
        argc == 2 && (strcmp(argv[1], "search") == 0 || strcmp(argv[1], "compare") == 0)));

    ifstream fin("countries.txt");
    assert(("I am not found 'countries.txt' file", fin.is_open()));

    cout << fixed;

    const int COUNT_OF_COUNTRIES = _lineCount();
    Country country[COUNT_OF_COUNTRIES];

    int iterator = 0;
    string line;
    while (getline(fin, line)) {
        int pos = 0;
        while (line[pos] != '\0') {
            // Country name
            country[iterator].name = _subLine(line, pos);

            // Capital name
            country[iterator].capital = _subLine(line, pos);

            // Domain
            country[iterator].domain = _subLine(line, pos);

            // Population
            country[iterator].population = atoi(_subLine(line, pos).c_str());

            // Area
            country[iterator].area = atoi(_subLine(line, pos).c_str());

            // GDB
            country[iterator].gdb = atoll(_subLine(line, pos).c_str());

            // Phone Code
            country[iterator].phonecode = atoi(_subLine(line, pos).c_str());
        }

        iterator++;
    }

    fin.close();

    if (strcmp(argv[1], "search") == 0) {
        string search_mode;

        //do {
            cout << "Input search mode (countryName / capital / domain) : ";
            cin >> search_mode;
        //} while (search_mode != "countryName" || search_mode != "capital" || search_mode != "domain");

        if (search_mode == "countryName") {
            string name;
            cout << "Input country name : ";
            cin >> name;

            bool is_find = false;
            for (Country current_country : country) {
                if (current_country.name == name) {
                    current_country.getInformation();
                    is_find = true;
                    break;
                }
            }

            if (!is_find) {
                cout << "Could not find country, whos name is " << name << endl;
            }
        } else if (search_mode == "capital") {
            string capital;
            cout << "Input capital : ";
            cin >> capital;

            bool is_find = false;
            for (Country current_country : country) {
                if (current_country.capital == capital) {
                    current_country.getInformation();
                    is_find = true;
                    break;
                }
            }

            if (!is_find) {
                cout << "Could not find country, whos capital is " << capital << endl;
            }
        } else {
            string domain;
            cout << "Input domain : ";
            cin >> domain;
            if (domain[0] != '.') {
                domain = "." + domain;
            }

            bool is_find = false;
            for (Country current_country : country) {
                if (current_country.domain == domain) {
                    current_country.getInformation();
                    is_find = true;
                    break;
                }
            }

            if (!is_find) {
                cout << "Could not find country, whos domain is " << domain << endl;
            }
        }
    } else {
        Country first_country;
        Country second_country;

        cout << "Input first country  : ";
        cin >> first_country.name;
        cout << "Input second country : ";
        cin >> second_country.name;

        bool is_find_first_country = false;
        bool is_find_second_country = false;
        for (Country current_country : country) {
            if (first_country.name == current_country.name) {
                first_country = current_country;
                is_find_first_country = true;
            }

            if (second_country.name == current_country.name) {
                second_country = current_country;
                is_find_second_country = true;
            }
        }

        if (!is_find_first_country) {
            cout << "Could not find information for '" << first_country.name << "'" << endl;
            return 0;
        }

        if (!is_find_second_country) {
            cout << "Could not find information for '" << second_country.name << "'" << endl;
            return 0;
        }

        char population_diff = _difference(first_country.population, second_country.population);
        char area_diff = _difference(first_country.area, second_country.area);
        char gdb_diff = _difference(first_country.gdb, second_country.gdb);

        cout << "=============================================\n";
        cout << "            | " << first_country.name << " | " << second_country.name << endl;
        cout << "=============================================\n";
        cout << " Capital    | " << first_country.capital << " | " << second_country.capital << endl;
        cout << " Domain     | " << first_country.domain  << " | " << second_country.domain << endl;
        cout << " Population | " << first_country.population << " " << population_diff << " " << second_country.population << endl;
        cout << " Area       | " << first_country.area << " " << area_diff << " " << second_country.area << endl;
        cout << " GDB        | " << _convertNumber(first_country.gdb) << gdb_diff << " " << _convertNumber(second_country.gdb) << endl;
        cout << " Phone Code | +" << first_country.phonecode << " | +" << second_country.phonecode << endl;
    }

    return 0;
}

string _convertNumber(long long number) {
    const long long TRILLION = (long long) 1e12;
    const long long BILLION = (long long) 1e9;
    const long long MILLION = (long long) 1e6;

    if (number > TRILLION) {
        double temp = (double) number / TRILLION;
        return to_string(temp) + " Trillion ";
    } else if (number > BILLION) {
        double temp = (double) number / BILLION;
        return to_string(temp) + " Billion ";
    } else if (number > MILLION) {
        double temp = (double) number / MILLION;
        return to_string(temp) + " Million ";
    } else {
        return to_string(number);
    }
}

char _difference(long long a, long long b) {
    if (a > b) {
        return '>';
    } else if (a < b) {
        return '<';
    } else {
        return '=';
    }
}

int _lineCount() {
    int result = 0;
    string temp;

    ifstream fin("countries.txt");
    while (getline(fin, temp)) {
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