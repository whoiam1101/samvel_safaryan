#include <iostream>
#include <cmath>

using namespace std;

// Implementation function, for return true if floating number argument <= 0.0
bool isLEZero(double x) {
    const double epsilon = 1e-9;
    
    if (abs(x) <= epsilon || x <= 0.0) {
        return true;
    }

    return false;
}

int main() {    

    // Declare rectangle height and width
    double width;
    double height;

    // Read width while width <= 0.0
    do {

        // Read width
        cout << "Print rectangle width : ";
        cin >> width;
    } while (isLEZero(width));

    // Read height while height <= 0.0
    do {

        // Read height
        cout << "Print rectangle height : ";
        cin >> height;
    } while (isLEZero(height));

    // Print rectangle area and perimeter  
    cout << "Rectangle area is " << width * height 
         << "\nRectangle perimeter is " << 2.0 * (width + height) << "\n";

    return 0;
}
