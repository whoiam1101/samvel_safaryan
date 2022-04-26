#include <iostream>
#include <ctime>
#include <random>
#include <vector>

#include "vector.hpp"

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"

using namespace std;

mt19937 gen(time(nullptr));

int _genNumber(int a = -100, int b = 100) {
    return gen() % (b - a + 1) + a;
}

int main() {
    Vector<int> my_vector;
    vector<int> stl_vector;

    cout << " push back testing:\n";
    for (int i = 0; i < 20; i++) {
        int rnd_number = _genNumber();
        my_vector.pushBack(rnd_number);
        stl_vector.push_back(rnd_number);
        if (my_vector[i] == stl_vector[i]) {
            cout << GREEN << "ACCEPTED: " << i + 1 << "\n";
        } else {
            cout << RED << "REJECTED: " << i + 1 << "\n";
        }
    }

    cout << endl;
    if (stl_vector.size() == my_vector.size()) {
        cout << GREEN << "Both SIZEs is equal\n";
    } else {
        cout << RED << "Both SIZEs isn't equal\n";
    }
    cout << endl;

    cout << " insert testing:\n";
    for (int i = 0; i < 20; i++) {
        int rnd_number = _genNumber();
        int rnd_index = _genNumber(0, stl_vector.size() - 1);
        my_vector.insert(rnd_index, rnd_number);
        stl_vector.insert(stl_vector.begin() + rnd_index, rnd_number);
        if (stl_vector.size() == my_vector.size()) {
            cout << GREEN << "ACCEPTED: Both SIZEs are equal\n";
        } else {
            cout << RED << "REJECTED: Both SIZEs aren't equal\n";
        }
        rnd_index = _genNumber(0, stl_vector.size() - 1);
        if (stl_vector[rnd_index] == my_vector[rnd_index]) {
            cout << GREEN << "ACCEPTED: " << i + 1 << endl;
        } else {
            cout << RED << "REJECTED: " << i + 1 << endl;
        }
    }

    cout << " erase testing\n";
    for (int i = 0; i < 10; i++) {
        int rnd_index = _genNumber(0, stl_vector.size() - 1);
        my_vector.erase(rnd_index);
        stl_vector.erase(stl_vector.begin() + rnd_index);
        bool is_equal = true;
        for (int i = 0; i < (int) stl_vector.size(); i++) {
            if (stl_vector[i] != my_vector[i]) {
                is_equal = false;
                break;
            }
        }
        if (is_equal) {
            cout << GREEN << "ACCEPTED: Both vectors are equal\n";
        } else {
            cout << RED << "REJECTED: Both vectors aren't equal\n";
        }
    }

    return 0;
}