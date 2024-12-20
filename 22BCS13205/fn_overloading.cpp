#include <iostream>
#include <cmath>
using namespace std;

class Complex {
 private:
    double real;
    double imag;

 public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operate(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operate(const Complex& other, int multiplierFlag) const {
        double realPart = real * other.real - imag * other.imag;
        double imagPart = real * other.imag + imag * other.real;
        return Complex(realPart, imagPart);
    }

    double operate() const {
        return sqrt(real * real + imag * imag);
    }

    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
};

int main() {
    int operationType;
    cout << "Enter Operation Type (1 for Addition, 2 for Multiplication, 3 for Magnitude): ";
    cin >> operationType;

    if (operationType == 1) {
        double real1, imag1, real2, imag2;
        cout << "Enter Complex Number 1 (real imaginary): ";
        cin >> real1 >> imag1;
        cout << "Enter Complex Number 2 (real imaginary): ";
        cin >> real2 >> imag2;

        Complex c1(real1, imag1);
        Complex c2(real2, imag2);
        Complex result = c1.operate(c2);

        cout << "Result: ";
        result.display();
        cout << endl;

    } else if (operationType == 2) {
        double real1, imag1, real2, imag2;
        cout << "Enter Complex Number 1 (real imaginary): ";
        cin >> real1 >> imag1;
        cout << "Enter Complex Number 2 (real imaginary): ";
        cin >> real2 >> imag2;

        Complex c1(real1, imag1);
        Complex c2(real2, imag2);
        Complex result = c1.operate(c2, 1);

        cout << "Result: ";
        result.display();
        cout << endl;

    } else if (operationType == 3) {
        double real, imag;
        cout << "Enter Complex Number (real imaginary): ";
        cin >> real >> imag;

        Complex c(real, imag);
        double magnitude = c.operate();

        cout << "Result: Magnitude = " << magnitude << endl;

    } else {
        cout << "Invalid operation type." << endl;
    }

    return 0;
}
