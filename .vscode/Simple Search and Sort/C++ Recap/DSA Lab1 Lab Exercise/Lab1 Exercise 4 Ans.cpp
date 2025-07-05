/*4. Write a C++ program to declare an integer variable, assign it a value, and 
use a pointer to display its address and value.*/

#include <iostream>
using namespace std;
int main() {
    int num = 42;    // Declare an integer variable and assign it a value
    int *ptr = &num; // Declare a pointer and store the address of num
  
    cout << "Value of num: " << num << endl;         
    cout << "Address of num: " << &num << endl;      // Print address of num
    cout << "Value using pointer: " << *ptr << endl; // Print value using pointer
    cout << "Pointer stores address: " << ptr << endl; // Print address stored in pointer
    return 0; 
}
