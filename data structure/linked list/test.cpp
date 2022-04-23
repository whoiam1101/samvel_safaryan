#include <list>
#include <iostream>
#include <ctime>
#include <random>

#include "linkedlist.cpp"

using namespace std;

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"

mt19937 gen(time(nullptr));

int _genInt(int a = -100, int b = 100) {
    return gen() % (b - a + 1) + a;
}

int _genOperation() {
    return _genInt(0, 4);
}

int main() {
    LinkedList<int> my_list;
    list<int> true_list;

    for (int i = 0; i < 100; i++) {
        int rnd_number = _genInt();
        my_list.addAtIndex(i, rnd_number);
        true_list.push_back(rnd_number);
    }

    for (int i = 0; i < 20; i++) {
        int rnd_index = _genInt(0, 19);
        list<int>::iterator it = true_list.begin();
        advance(it, rnd_index);
        if (my_list[rnd_index] == *it) {
            cout << GREEN << "ACCEPTED : Test id = " << i + 1 << "\n";
        } else {
            cout << RED << "REJECTED : Test id = " << i + 1 << "\n";
        }
    }

    cout << my_list << endl;

    return 0;
}