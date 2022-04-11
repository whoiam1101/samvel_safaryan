#include <iostream>

using namespace std;

// Declare isPalindrom function
bool isPalindrom(string);

int main() {
    // Declare word
    string word;

    // Input word
    cout << "Input : ";
    cin >> word;

    // Print true if word is palindrom, otherwise print false
    cout << "Output: " << (isPalindrom(word) ? "true\n" : "false\n");

    return 0;
}

// Define isPalindrom function
// ignore alphabetical letters case
// return true if word is palindrom
// return false if word isn't palindrom
bool isPalindrom(string word) {
    // length of word
    int length = word.size();
    
    const int difference = 'a' - 'A';

    for (int i = 0; i < length / 2; i++) {
        // Ignore letters case upper_case -> lower_case
        if ('A' <= word[i] && word[i] <= 'Z') {
            word[i] += difference;
        }
        
        // Ignore letters case upper_case -> lower_case
        if ('A' <= word[length - i - 1] && word[length - i - 1] <= 'Z') {
            word[length - i - 1] += difference;
        }

        // if symetric position characters isn't equals
        // then this word isn't a palindrom
        if (word[i] != word[length - i - 1]) {
            return false;
        }
    }

    return true;
}
