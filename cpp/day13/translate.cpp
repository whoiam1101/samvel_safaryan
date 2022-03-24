#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <sstream>
#include <clocale>

using namespace std;

const string LARM = "աբգդեզէըթժիլխծկհձղճմյնշոչպջռսվտրցւփքօֆ";
const string UARM = "ԱԲԳԴԵԶԷԸԹԺԻԼԽԾԿՀՁՂՃՄՅՆՇՈՉՊՋՌՍՎՏՐՑՒՓՔՕՖ";

char _armenianLowerCase(char c) {
  for (int i = 0; i < (int) UARM.size(); i++) {
    if (c == UARM[i]) {
      return LARM[i];
    }
  }

  return c;
}

bool _isArmenianLetter(char c) {
  for (int i = 0; i < (int) LARM.size(); i++) {
    if (LARM[i] == c || UARM[i] == c) return true;
  }

  if (c == 'և') return true;
  return false;
}

string _lowerCase(string s) {
  string result = "";
  for (char c : s) {
    if ('A' <= c && c <= 'Z') {
      result += (char) (c + ('a' - 'A'));
    } else {
      result += _armenianLowerCase(c);
    }
  }

  return result;
}

bool _isAlpha(char c) {
  bool is_british = ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
  return _isArmenianLetter(c) || is_british;
}

int main() {
  setlocale(LC_ALL, "");

  string sentence;
  cout << "Enter sentence\n";
  cout << "$ ";
  getline(cin, sentence);

  int pos = 0;
  while (pos < (int) sentence.size()) {
    while (pos < (int) sentence.size() && !_isAlpha(sentence[pos])) {
      cout << sentence[pos];
      pos++;
    }

    string word = "";
    while (pos < (int) sentence.size() && _isAlpha(sentence[pos])) {
      word += sentence[pos];
      pos++;
    }

    ifstream fin;
    if (_isArmenianLetter(word[0])) fin.open("hy-en.txt");
    else fin.open("en-hy.txt");

    string temp;
    while (fin >> temp) {
      if (_lowerCase(temp) == _lowerCase(word)) {
        fin >> temp;
        fin >> temp;
        cout << temp;
        break;
      }
    }

    fin.close();
  }

  cout << endl;

  return 0;
}