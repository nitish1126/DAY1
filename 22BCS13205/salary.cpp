#include <iostream>
using namespace std;

class SalaryCalculator {
public:
    int calculateSalary(int stipend) {
        return stipend;
    }

    int calculateSalary(int baseSalary, int bonuses) {
        return baseSalary + bonuses;
    }

    int calculateSalary(int baseSalary, int bonuses, int incentives) {
        return baseSalary + bonuses + incentives;
    }
};

int main() {
    SalaryCalculator calculator;

    int stipend;
    cout << "Enter stipend for Intern: ";
    cin >> stipend;

    int baseSalaryEmployee, bonusesEmployee;
    cout << "Enter base salary for Regular Employee: ";
    cin >> baseSalaryEmployee;
    cout << "Enter bonuses for Regular Employee: ";
    cin >> bonusesEmployee;

    int baseSalaryManager, bonusesManager, incentivesManager;
    cout << "Enter base salary for Manager: ";
    cin >> baseSalaryManager;
    cout << "Enter bonuses for Manager: ";
    cin >> bonusesManager;
    cout << "Enter incentives for Manager: ";
    cin >> incentivesManager;

    int internSalary = calculator.calculateSalary(stipend);
    int employeeSalary = calculator.calculateSalary(baseSalaryEmployee, bonusesEmployee);
    int managerSalary = calculator.calculateSalary(baseSalaryManager, bonusesManager, incentivesManager);

    cout << "Intern Salary: " << internSalary << endl;
    cout << "Employee Salary: " << employeeSalary << endl;
    cout << "Manager Salary: " << managerSalary << endl;

    return 0;
}
