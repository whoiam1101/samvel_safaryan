#include <iostream>

using namespace std;

// Declare: the greatest common divisor of two integer numbers
// Time complexity = O(log)
long long gcd(long long, long long);

// Declare: the least common multiple of two integer numbers
// Time complexity = O(log)
long long lcm(long long, long long);

int main() {

    long long a, b;
    
    cout << "Enter the first integer number: ";
    cin >> a;

    cout << "Enter the second integer number: ";
    cin >> b;

    cout << "The greatest common divisor of " << a << " and " << b << " is " << gcd(a, b) << endl;
    cout << "The least common multiple of " << a << " and " << b << " is " << lcm(a, b) << endl;

    return 0;
}

// Define: Implementation the recursive version of Euclidean algorithm
long long gcd(long long a, long long b) {
    if (b == 0LL) return a;
    return gcd(b, a % b);
}

// Define: Implementation the least common multiple of two integers
long long lcm(long long a, long long b) {
    if (a == 0LL || b == 0LL) return 0LL;
    return a * b / gcd(a, b);
}
