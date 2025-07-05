#include <iostream>  
using namespace std; 
int main() {
    int num = 10;    
    int *ptr = &num; // Declare a pointer and store the address of num
    cout << "Value of num: " << num << endl;      
    cout << "Address of num: " << &num << endl;    // Print the address of num
    cout << "Value stored at ptr: " << *ptr << endl; // Dereference ptr to get value of num
    cout << "Address stored in ptr: " << ptr << endl; // Print the address stored in ptr
    return 0; 
}
