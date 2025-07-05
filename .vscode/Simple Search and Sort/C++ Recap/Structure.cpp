#include <iostream>  
using namespace std; 
struct Student { //define a structure named Student to store student's name, age, GPA
    string name;  
    int age;      
    float gpa;
   float salary;    
};
int main() {
    Student stud = {"Dawit", 20, 3.90,30000}; //initialize a structure variable
    // Print the structure members
    cout << "Student Name: " << stud.name << endl; 
    cout << "Student Age: " << stud.age << endl;   
    cout << "Student GPA: " << stud.gpa << endl;
    cout << "Student Salary: " << stud.salary << endl;
    return 0;
}
