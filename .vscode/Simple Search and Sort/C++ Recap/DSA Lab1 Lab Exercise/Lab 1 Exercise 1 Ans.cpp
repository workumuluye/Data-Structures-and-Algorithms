// 1. Write a program to take 5 numbers as input from the user, store them in an array, and display their sum.

#include <iostream>  
using namespace std; 
int main() {
    int arr[5];    //array of size 5
    int sum = 0;   //variable to store sum
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];  // Store user input in array
        sum += arr[i];  // Add each element to sum
    }
    cout << "Sum of the numbers: " << sum << endl;

    return 0;
}
