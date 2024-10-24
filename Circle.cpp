#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the distance between two points (x1, y1) and (x2, y2)
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the radius of the circle
double radius(double x1, double y1, double x2, double y2) {
    return distance(x1, y1, x2, y2);
}

// Function to calculate the circumference of the circle
double circumference(double r) {
    const double pi = 3.1416;
    return 2 * pi * r;
}

// Function to calculate the area of the circle
double area(double r) {
    const double pi = 3.1416;
    return pi * r * r;
}

int main() {
    double x1, y1, x2, y2;

    // Input: the center and a point on the circle
    cout << "Enter the coordinates of the center of the circle (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of a point on the circle (x2, y2): ";
    cin >> x2 >> y2;

    // Calculate radius
    double r = radius(x1, y1, x2, y2);

    // Output results
    cout << "Radius: " << r << endl;
    cout << "Diameter: " << 2 * r << endl;
    cout << "Circumference: " << circumference(r) << endl;
    cout << "Area: " << area(r) << endl;

    return 0;
}
