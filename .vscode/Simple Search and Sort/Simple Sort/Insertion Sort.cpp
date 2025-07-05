#include <iostream> 
using namespace std; 
void insertionsort(int arra[], int n) { //function that perform Insertion Sort that take integer array & its size
    for (int i = 1; i < n; i++) { //loop start from the second element i.e. index 1 and run through the array
        int key = arra[i];//store the current element the one to be inserted in key.
        int j = i - 1;//start comparing with the previous element(j points to the previous element:sorted subarray)
        //j is valid and the element at j is greater than key,continue shifting elements to the right key is > the compared element
        while (j >= 0 && arra[j] > key) {//shift elements of sorted part to the right to create space
            arra[j + 1] = arra[j];//move larger element one step right
            j--;//move to the previous element for comparison
        }
        arra[j + 1] = key;//insert the key in the correct sorted position
    }
}
void printarray(int arra[], int n) {//function to print an array
    for (int i = 0; i < n; i++) {
        cout << arra[i] << " "<< endl;//display each element
    }
    cout << endl;
}
int main() {
    int arra[] = {12, 11, 13, 100, 7, 4, 70};//declare and initialize an array
    int n = sizeof(arra) / sizeof(arra[0]);//calculate array size
    insertionsort(arra, n); //call insertion sort function
    cout << "Sorted array by Insertion Sort: ";
    printarray(arra, n);//display sorted array
    return 0;
}
