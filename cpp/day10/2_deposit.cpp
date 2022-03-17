#include <iostream>
#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {
    assert(argc == 4);

    float deposit      = atof(argv[1]);
    float percentage   = atof(argv[2]) / 1200.0;
    int count_of_month = atoi(argv[3]);

    cout << fixed;
    cout << setprecision(2);

    const int SECONDS_PER_DAY = 24 * 60 * 60 * 30;

    for (int i = 1; i <= count_of_month; i++) {
        float delta = deposit * percentage;
        float current_deposit = delta + deposit;

        time_t t = time(0) + SECONDS_PER_DAY * i;
        char* time = ctime(&t);

        cout << "Date: " << time
             << " | Prev deposit: " << deposit
             << " | Current deposit: " << current_deposit
             << " | Added in this month: " << delta << "\n\n";

        deposit = current_deposit;
    }

    return 0;
}