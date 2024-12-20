#include <iostream>
using namespace std;

int main() {
    long long number; 
    cout << "Enter a number: ";
    cin >> number;

    
    if (number < 0) {
        number = -number; 
    }

    int count = 0;

    
    if (number == 0) {
        count = 1;
    } else {
        while (number > 0) {
            number /= 10; 
            count++; 
        }
    }

    cout << "The number of digits is: " << count << endl;

    return 0;
}