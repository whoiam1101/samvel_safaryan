#include <ctime>
#include <iostream>

using namespace std;

string _subString(string, int, int);

int main() {
    long long second;

    cout << "Input: ";
    cin >> second;

    time_t date_t = second;
    string date   = ctime(&date_t);
    string month  = _subString(date, 4, 3);
    string day    = _subString(date, 8, 2);
    string year   = _subString(date, 11, 5);
    string time   = _subString(date, 20, 4);

    cout << month << " " << day << " " << year << " " << time << endl;

    return 0;
}

string _subString(string s, int l, int count) {
    string result = "";
    for (int i = l; i < l + count; i++) {
        result += s[i];
    }

    return result;
}