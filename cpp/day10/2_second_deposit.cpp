#include <iostream>
#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

string _date(string time);

int main(int argc, char* argv[]) {
  assert(argc == 4);

  float deposit      = atof(argv[1]);
  float percentage   = atof(argv[2]) / 1200.0;
  int count_of_month = atoi(argv[3]);

  cout << fixed;
  cout << setprecision(2);

  const int SECONDS_PER_MONTH = 24 * 60 * 60 * 30;

  float sum_delta = 0.0;

  cout << "   Date   | prev deposit | current deposit | income per month\n";

  for (int i = 1; i <= count_of_month; i++) {
    float delta = deposit * percentage;
    sum_delta += delta;
    float current_deposit = delta + deposit;

    time_t t = time(0) + SECONDS_PER_MONTH * i;
    string time = ctime(&t);

    cout << _date(time)
          << " | " << deposit
          << "amd | " << current_deposit
          << "amd | " << delta << "amd\n\n";

    deposit = current_deposit;
  }

  cout << "Interest income: " << sum_delta << "amd\n";

  return 0;
}

// Thu Mar 14 10:08:04 2024
string _date(string time) {
  int pos = 1;
  for (; time[pos] != ' '; pos++) {}
  pos++;

  // Month
  string month = "";
  for (; time[pos] != ' '; pos++) month += time[pos];

  // Day
  while (time[pos] == ' ') pos++;
  string day = "";
  for (; time[pos] != ' '; pos++) day += time[pos];

  if (day.size() == 1) day = "0" + day;

  pos++;
  for (; time[pos] != ' '; pos++) {}
  pos++;

  // Year
  string year = "";
  for (; time[pos] != '\n'; pos++) year += time[pos];

  string Month[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  };

  for (pos = 1; month != Month[pos - 1]; pos++) {}
  if (1 <= pos && pos <= 9) {
    return day + ".0" + to_string(pos) + "." + year;
  } else {
    return day + "." + to_string(pos) + "." + year;
  }
}
