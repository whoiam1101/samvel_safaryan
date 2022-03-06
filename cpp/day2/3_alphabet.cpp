#include <iostream>

using namespace std;

// Vowel letters is A, E, I, O, U, and sometimes Y.


// Implementation function: return true if symbol is alphabetical letter
// Otherwise return false
bool isalpha(char symbol) {
    if (('a' <= symbol && symbol <= 'z') || ('A' <= symbol && symbol <= 'Z')) {
        return true;
    }

    return false;
}

int main() {

    // Declare alphabet letter
    char alphabet_letter;

    // Read alphabet_letter while it is not alphabet letter
    do {

        // Read alphabet_letter
        cout << "Input alphabet: ";
        cin >> alphabet_letter;

    // I use the function isalpha in cctype library,
    // for check Is symbol in alphabet
    } while (!isalpha(alphabet_letter));

    // use switch statement for check 
    // is input letter vowel or consonant
    switch (alphabet_letter) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            cout << "'" << alphabet_letter << "' is vowel\n";
            break;
        default:
            cout << "'" << alphabet_letter << "' is consonant\n";
            break;
    }

    return 0;
}
