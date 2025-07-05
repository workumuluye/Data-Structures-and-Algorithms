/* 2. Create a structure called Employee with attributes name, age, and salary. 
Write a program to input and display details of an employee.*/
#include <iostream>
using namespace std;

struct staff { //define a structure named Employee to store name, age, and salary of the employee
    string name;  
    int age;
    string gender;       
    double salary; 
};
int main() {
    staff emp; // Declare a structure variable
    // Taking input from the user
    cout << "Enter staff name: ";
    getline(cin, emp.name);
    cout << "Enter staff age: ";
    cin >> emp.age;
    cout << "Enter staff gender: ";
    cin >> emp.gender;
    cout << "Enter staff salary: ";
    cin >> emp.salary;
    //displaying employee details
    cout << "\nStaff Details:\n";
    cout << "Name: " << emp.name << endl;
    cout << "Age: " << emp.age << endl;
    cout << "Salary: $" << emp.salary << endl;
    return 0; 
}
