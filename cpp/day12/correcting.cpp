#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

bool _isAlpha(char);
char _lowerCase(char);
char _upperCase(char);

int main() {
    clock_t start_execution_time = clock();

    try {
        //TODO read user input single sentence
        string sentence;

        cout << "Input: ";
        getline(cin, sentence);

        ofstream fout("corrected.txt");
        if (!fout.is_open()) {
            fout.close();
            throw "corrected.txt file not found!!!";
        }

        //TODO for loop all word in sentence and correct they
        int pos = 0;

        while (pos < (int) sentence.size()) {
            //TODO open files and check if they are exists.
            ifstream fin("british-english");

            //TODO throw exception if files are not finding
            if (!fin.is_open()) {
                fout.close();
                fin.close();
                throw "british-english dictionary file not found!!!";
            }

            while (pos < (int) sentence.size() && !_isAlpha(sentence[pos])) {
                fout << sentence[pos];
                pos++;
            }

            int word_start_position = pos;
            string word = "";

            while (pos < (int) sentence.size() && _isAlpha(sentence[pos])) {
                word += sentence[pos];
                pos++;
            }

            string temp;

            bool is_reading = true;

            while (is_reading && fin >> temp) {
                if (temp.size() == word.size()) {
                    int incorrect_count = 0;

                    for (int i = 0; i < (int) word.size(); i++) {
                        if (_lowerCase(temp[i]) != _lowerCase(word[i])) {
                            incorrect_count++;
                        }
                    }

                    if (incorrect_count <= 1) {
                        for (int i = 0; i < (int) temp.size(); i++) {
                            if ('a' <= word[i] && word[i] <= 'z') {
                                fout << _lowerCase(temp[i]);
                            } else if ('A' <= word[i] && word[i] <= 'Z') {
                                fout << _upperCase(temp[i]);
                            } else {
                                fout << temp[i];
                            }
                        }
                        is_reading = false;
                    }
                }
            }

            if (is_reading) {
                fout << word;
            }

            //TODO Close opened files
            fin.close();
        }

        fout.close();
    } catch (const char* message) {
        cout << message << endl;
    }

    cerr << "Execution time := " << 1000.0 * (double) (clock() - start_execution_time) / CLOCKS_PER_SEC << "ms\n";

    return 0;
}

bool _isAlpha(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

char _lowerCase(char c) {
    if ('A' <= c && c <= 'Z') {
        return c + ('a' - 'A');
    }

    return c;
}

char _upperCase(char c) {
    if ('a' <= c && c <= 'z') {
        return c + ('A' - 'a');
    }

    return c;
}