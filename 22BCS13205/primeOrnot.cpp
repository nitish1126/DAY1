#include <iostream>
#include <cmath> 
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false; 
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false; 
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false; 
        }
    }

    return true; 
}
int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }

    return 0;
}