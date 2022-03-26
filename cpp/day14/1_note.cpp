#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

string _subStr(string, int, int);

void _showNote(string);
void _showAllNote();
void _showHelp();
void _printDate(string);

enum WeekDay {
    SATURDAY = 0,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

struct Note {
    string date = "01_01_0000";
    string note = "";

    void inputDate() {
        cout << "Input date: ";
        cin >> date;
    }

    void addNote() {
        inputDate();
        cout << "Add Note: ";
        cin.ignore();
        getline(cin, note);
        string file_name = "./notes/" + date;
        ofstream fout(file_name.c_str(), ios::app);
        fout << note << endl;

        ifstream hin("history");
        string temp;
        bool is_file_exist = false;
        while (getline(hin, temp)) {
            if (temp == date) {
                is_file_exist = true;
                break;
            }
        }

        if (!is_file_exist) {
            ofstream hout("history", ios::app);
            hout << date << endl;
            hout.close();
        }

        hin.close();
        fout.close();
    }
};

int main() {
    bool is_not_exit = true;
    while (is_not_exit) {
        string command;
        cout << "Do you want to add another note (command: add / exit / show / help)\n";
        cout << "$ ";
        cin >> command;
        if (command == "add") {
            Note note;
            note.addNote();
        } else if (command == "exit") {
            _showAllNote();
            is_not_exit = false;
        } else if (command == "show") {
            string date;
            cout << "Input date: ";
            cin >> date;
            _showNote(date);
        } else if (command == "help") {
            _showHelp();
        } else {
            cout << "Command not found!" << endl;
        }
    }
    return 0;
}

void _showHelp() {
    cout << " Help for user:\n";
    cout << " Command add: add date(dd.mm.yyyy) and note\n";
    cout << " Command exit: show all notes and exit program\n";
    cout << " Command show: input date and show all notes in that date\n";
    cout << " Command help: show all command\n";
}

void _showNote(string date) {
    string file_name = "./notes/" + date;
    ifstream fin(file_name.c_str());
    if (!fin.is_open()) {
        cout << "In " << date << " you have not added note\n";
    } else {
        _printDate(date);
        string note;
        while (getline(fin, note)) {
            cout << "   Note: " << note << endl;
        }
    }
    fin.close();
}

void _showAllNote() {
    ifstream hin("history");
    string date;
    while (getline(hin, date)) {
        _showNote(date);
    }
    hin.close();
}

string _subStr(string str, int l, int r) {
    string result = "";
    for (int i = l; i <= r; i++) {
        result += str[i];
    }
    return result;
}

void _printDate(string date) {
    int dd = atoi(_subStr(date, 0, 1).c_str());
    int mm = atoi(_subStr(date, 3, 4).c_str());
    int yyyy = atoi(_subStr(date, 6, 9).c_str());

    // Zeller’s Congruence
    if (mm <= 2) {
        mm += 12;
        yyyy--;
    }

    int y = yyyy % 100;
    yyyy /= 100;
    WeekDay weekday = (WeekDay) ((dd + 13 * (mm + 1) / 5 + y + y / 4 + yyyy / 4 + 5 * yyyy) % 7);

    string week_days[] = {"Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};
    cout << week_days[weekday] << " " << date << endl;
}