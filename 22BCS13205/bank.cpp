#include <iostream>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double bal) : balance(bal) {}
    virtual void calculateInterest() = 0;  
};

class SavingsAccount : public Account {
private:
    double rate; 
    int time;     
public:
    SavingsAccount(double bal, double r, int t) : Account(bal), rate(r), time(t) {}

    void calculateInterest() override {
        double interest = balance * (rate / 100) * time;
        cout << "Savings Account Interest: " << interest << endl;
    }
};

class CurrentAccount : public Account {
private:
    double fee; 
public:
    CurrentAccount(double bal, double f) : Account(bal), fee(f) {}

    void calculateInterest() override {
        balance -= fee; 
        cout << "Balance after fee deduction: " << balance << endl;
    }
};

int main() {
    int accountType;
    double balance, rate, fee;
    int time;

    cout << "Enter Account Type (1 for Savings, 2 for Current): ";
    cin >> accountType;

    if (accountType < 1 || accountType > 2) {
        cout << "Invalid account type." << endl;
        return 0;
    }

    cout << "Enter Account Balance: ";
    cin >> balance;

    if (accountType == 1) {
        cout << "Enter Interest Rate (as a percentage): ";
        cin >> rate;
        cout << "Enter Time in years: ";
        cin >> time;

        SavingsAccount savingsAccount(balance, rate, time);
        savingsAccount.calculateInterest();
    } else if (accountType == 2) {
       cout << "Enter Monthly Maintenance Fee: ";
        cin >> fee;

        CurrentAccount currentAccount(balance, fee);
        currentAccount.calculateInterest();
    }

    return 0;
}
