#include <iostream>  
using namespace std; 
void bubblesort(int arra[], int n) { //function to perform Bubble Sort
    for (int i = 0; i < n-1; i++) {//loop through the array n-1 times (i outer loop counter controls how many passes are done)
        for (int j = 0; j < n - i - 1; j++) {//compares adjacent elements up to the unsorted portion (reducing each time)
                           //i is current pass number(buuble sort will have n-1 passes).
            if (arra[j] > arra[j + 1]) { //If the left element is greater than the right, they are in the wrong order.
                swap(arra[j], arra[j + 1]);//Swap the two elementsSwap the two elements 
            }
        }
    }
}
void printarray(int arra[], int n) {//function to print an array
    for (int i = 0; i < n; i++) {
        cout << arra[i] << " "<< endl;//display each element
    }
    cout << endl;
}
int main() {
    int arra[] = {5, 1, 12, 4, 2, 8, 21, 7, 10};//declare and initialize an array
    int n = sizeof(arra) / sizeof(arra[0]);
    bubblesort(arra, n);//call bubble sort function
    cout << "Sorted array by Bubble Sort: ";
    printarray(arra, n);//display sorted array
    return 0; 
}
