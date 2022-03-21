#include <iostream>
#include <cstring>

using namespace std;

void _swap(int&, int&);
void _nextPermutation(int*, const int);
string _permutation(string, int*);

int main() {
    string sentence;

    cout << "Input: ";
    getline(cin, sentence);

    const int LENGTH = sentence.size();
    int* permutation = new int[LENGTH];

    int factorial = 1;

    for (int i = 0; i < LENGTH; i++) {
        permutation[i] = i;
        factorial *= i + 1;
    }

    cout << "Output:\n";

    string all_permutations[factorial];

    for (int i = 0; i < factorial; i++) {
        all_permutations[i] = _permutation(sentence, permutation);
        _nextPermutation(permutation, LENGTH);

        bool is_exist = false;

        for (int j = 0; j < i; j++) {
            if (all_permutations[i] == all_permutations[j]) {
                is_exist = true;
            }
        }

        if (!is_exist) {
            cout << all_permutations[i] << endl;
        }
    }

    return 0;
}

void _swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void _nextPermutation(int* permutation, const int LENGTH) {
    if (LENGTH == 1) {
        return;
    }

    // Step 1
    int pos = LENGTH - 1;
    while (permutation[pos - 1] > permutation[pos]) {
        pos--;
    }
    pos--;

    // Step 2
    int swap_pos = LENGTH - 1;
    while (permutation[swap_pos] < permutation[pos]) {
        swap_pos--;
    }
    _swap(permutation[pos], permutation[swap_pos]);

    // Step 3
    for (int i = 0; 2 * i < LENGTH - pos - 1; i++) {
        _swap(permutation[pos + 1 + i], permutation[LENGTH - i - 1]);
    }
}

string _permutation(string sentence, int* permutation) {
    string result = "";

    for (int i = 0; i < sentence.size(); i++) {
        result += sentence[permutation[i]];
    }

    return result;
}