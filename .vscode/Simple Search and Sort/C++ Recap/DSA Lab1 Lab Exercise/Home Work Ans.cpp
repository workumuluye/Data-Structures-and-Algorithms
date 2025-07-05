#include <iostream>
using namespace std;

// Define the student structure
struct Student {
    string name;
    int age;
    double GPA;
};

// Function to find the student with the highest GPA
Student* findTopStudent(Student* students, int size) {
    if (size == 0) return nullptr;
    
    Student* topStudent = &students[0];
    for (int i = 1; i < size; i++) {
        if (students[i].GPA > topStudent->GPA) {
            topStudent = &students[i];
        }
    }
    return topStudent;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    
    Student students[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Enter name, age, and GPA for student " << i + 1 << ": ";
        cin >> students[i].name >> students[i].age >> students[i].GPA;
    }
    
    Student* topStudent = findTopStudent(students, n);
    
    if (topStudent) {
        cout << "\nStudent with the highest GPA:\n";
        cout << "Name: " << topStudent->name << "\n";
        cout << "Age: " << topStudent->age << "\n";
        cout << "GPA: " << topStudent->GPA << "\n";
    }
    
    return 0;
}
