#include <iostream>
#include <string>
using namespace std;

class Employee {
  protected:
    string name;
    int id;
    int salary;
     
     public:
    Employee(const string& empName, int empID, int empSalary)
        : name(empName), id(empID), salary(empSalary) {}

    virtual void displayEarnings() const = 0;
};

class Manager : public Employee {
    private:
    int rating;

           public:
    Manager(const string& empName, int empID, int empSalary, int empRating)
        : Employee(empName, empID, empSalary), rating(empRating) {}

    void displayEarnings() const override {
        int bonus = (rating * 0.1) * salary;
        int totalEarnings = salary + bonus;
        cout << "Employee: " << name << " (ID: " << id << ")" << endl;
        cout << "Role: Manager" << endl;
        cout << "Base Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Earnings: " << totalEarnings << endl;
    }
};

class Developer : public Employee {
    private:
    int extraHours;

      public:
    Developer(const string& empName, int empID, int empSalary, int empExtraHours)
        : Employee(empName, empID, empSalary), extraHours(empExtraHours) {}

    void displayEarnings() const override {
        int overtimeCompensation = extraHours * 500;
        int totalEarnings = salary + overtimeCompensation;
        cout << "Employee: " << name << " (ID: " << id << ")" << endl;
        cout << "Role: Developer" << endl;
        cout << "Base Salary: " << salary << endl;
        cout << "Overtime Compensation: " << overtimeCompensation << endl;
        cout << "Total Earnings: " << totalEarnings << endl;
    }
};

int main() {
    int employeeType;
    cout << "Enter Employee Type (1 for Manager, 2 for Developer): ";
    cin >> employeeType;

    if (employeeType == 1) {
        string name;
        int id, salary, rating;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Performance Rating (1–5): ";
        cin >> rating;

        if (rating < 1 || rating > 5) {
            cout << "Invalid rating." << endl;
            return 0;
        }

        Manager manager(name, id, salary, rating);
        manager.displayEarnings();
    } else if (employeeType == 2) {
        string name;
        int id, salary, extraHours;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Extra Hours Worked: ";
        cin >> extraHours;

        if (extraHours < 0 || extraHours > 100) {
            cout << "Invalid extra hours." << endl;
            return 0;
        }

        Developer developer(name, id, salary, extraHours);
        developer.displayEarnings();
    } else {
        cout << "Invalid employee type." << endl;
    }
    return 0;
}
