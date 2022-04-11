#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>

#include "substring.h"

using namespace std;

string _subString(string s, int l, int r) {
    string result = "";
    for (int i = l; i <= r; i++) {
        result += s[i];
    }
    return result;
}

int _roomsCount(string file_name) {
    file_name = "Hotels/" + file_name + ".txt";
    ifstream fin(file_name.c_str());
    assert((file_name + " file not found!", fin.is_open()));
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

bool _isEqual(string a, string b) {
    return strcmp(a.c_str(), b.c_str()) == 0;
}