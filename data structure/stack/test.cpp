#include <bits/stdc++.h>

#include "stack.cpp"

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
    Stack<int> stack;
    list<int> true_stack;

    for (int i = 0; i < 100; i++) {
        int rnd_number = _genInt();
        stack.push(rnd_number);
        true_stack.push_back(rnd_number);
    }

    for (int i = 0; i < 20; i++) {
        if (stack.peek() == true_stack.back()) {
            cout << GREEN << "ACCEPTED : Test id = " << i + 1 << "\n";
        } else {
            cout << RED << "REJECTED : Test id = " << i + 1 << "\n";
        }
        stack.pop();
        true_stack.pop_back();
    }

    return 0;
}