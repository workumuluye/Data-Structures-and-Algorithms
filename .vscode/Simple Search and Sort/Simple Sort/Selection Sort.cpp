#include <iostream>  
using namespace std; 
void selectionsort(int arra[], int n) {//function that perform SS (take integer array array & its size n)
    //Each iteration places the smallest element in the unsorted part at position i.
    for (int i = 0; i < n - 1; i++) {//loop through each element
        int minindex = i;//assume the current index is the minimum
        for (int j = i + 1; j < n; j++) {//find the index of the minimum element in the remaining array to the right of i
            if (arra[j] < arra[minindex]) {
                minindex = j;//update minindex if a smaller element is found at position j
            }
        }
        //Swaps the smallest found element with the current element at position i
        swap(arra[i], arra[minindex]);
    }
}
void printarray(int arra[], int n) { //define function to print an array
    for (int i = 0; i < n; i++) {
        cout << arra[i] << " "; //loop through the array and display each element
    }
    cout << endl;
}
int main() {
    int arra[] = {64, 25, 12, 41, 22, 23, 37, 14}; //declare and initialize an array
    //Calculate the number of elements in the array by dividing total size by size of one element
    int n = sizeof(arra) / sizeof(arra[0]);
    selectionsort(arra, n); //call selection sort function to sort the array
    cout << "Array Sorted by Selection Sort: ";
    printarray(arra, n); //Call printarray function to display sorted array element
    return 0;
}
