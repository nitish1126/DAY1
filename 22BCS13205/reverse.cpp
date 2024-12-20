#include <iostream>
using namespace std;

int main() {
    int number, reversedNumber = 0;

    cout << "Enter an integer: ";
    cin >> number;

    int originalNumber = number;

    while (number != 0) {
        int digit = number % 10; 
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10; 
    }
    cout << "The reverse of " << originalNumber << " is " << reversedNumber << endl;

    return 0;
}