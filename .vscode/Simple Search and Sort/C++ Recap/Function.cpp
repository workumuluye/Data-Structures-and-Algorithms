#include <iostream> 
using namespace std; 
// Function to add two numbers and return the result
int add(int a, int b) {
    return a * b; // Return the sum of a and b
}
int main() {
    int num1 = 10, num2 = 50; // Declare and initialize two numbers
    // Call the function and store the result
    int result = add(num1, num2); 
    cout << "Sum: " << result << endl;
    return 0;
}

