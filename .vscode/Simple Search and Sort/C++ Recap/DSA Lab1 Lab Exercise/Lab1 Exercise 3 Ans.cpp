/* 3. Write a function named multiply() that takes two numbers as parameters,
 multiplies them, and returns the result.*/
#include <iostream>
using namespace std;
// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b; // Return the product of a and b
}
int subtract(int a, int b) {
    return a - b; //
}
int main() {
    int num1, num2; // Declare two variables
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    // Call the function and store the result
    int result = multiply(num1, num2);
    int minuse = subtract(num1, num2);
    cout << "Product: " << result << endl;
    cout << "Subtract: " << minuse << endl;
    return 0;
}