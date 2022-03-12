#include <iostream>
#include <cstring>

using namespace std;

int main() {

    // Declare sentence
    string sentence;

    // Read line
    cout << "Input sentence: ";
    getline(cin, sentence);

    // Declare count of B words
    int count_of_B_words  = 0;

    // For loop all letters in sentence
    for (int i = 0; sentence[i] != '\0';) {
        int count_of_B_letter = 0;

        // If start new word then satrting count of B and b letters in word
        while (sentence[i] != ' ' && sentence[i] != '\0') {
            if (sentence[i] == 'B' || sentence[i] == 'b') {
                count_of_B_letter++;
            }

            i++;
        }

        if (count_of_B_letter == 2) {
            count_of_B_words++;
        }

        i++;
    }

    // Print count of 2B letters
    cout << "Count words in sentence with 2 B: " << count_of_B_words << endl;

    return 0;
}
