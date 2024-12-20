#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;
double area(double radius) {
    return PI * radius * radius;
}
double area(double length, double width) {
    return length * width;
}
double area(double base, float height) {
    return 0.5 * base * height;
}
int main() {
    double radius, length, width, base;
    float height;
    cout << "Enter the radius (R): ";
    cin >> radius;
    cout << "Area of the circle: " << area(radius) << endl;

    cout << "Enter the length (L) and width (B): ";
    cin >> length >> width;
    cout << "Area of the rectangle: " << area(length, width) << endl;

    cout << "Enter the base (B) and height (H): ";
    cin >> base >> height;
    cout << "Area of the triangle: " << area(base, height) << endl;

    return 0;
}