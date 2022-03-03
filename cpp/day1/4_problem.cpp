#include <iostream>

using namespace std;

int main() {

    // Declare const variable for keep count of legs
    const int chickens_legs_count = 2;
    const int cows_legs_count = 4;
    const int pigs_legs_count = 4;

    // Declare count of animals
    int chickens_count;
    int cows_count;
    int pigs_count;

    cout << "Hello my friend, I am a farmer, please help me\n" <<
            "I tell to you my animals count, and you tell me count our legs\n";

    // Read chickens count
    cout << "Chickens count : ";
    cin >> chickens_count;

    // Read cows count
    cout << "Cows count : ";
    cin >> cows_count;

    // Read pigs count
    cout << "Pigs count : ";
    cin >> pigs_count;

    // Calculate and print count of all animal legs
    cout << "The count of all animal legs is " << 
            chickens_count * chickens_legs_count +
            cows_count     * cows_legs_count     +
            pigs_count     * pigs_legs_count 
    << endl;
    
    return 0;
}
