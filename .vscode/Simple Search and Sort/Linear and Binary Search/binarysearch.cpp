#include <iostream> 
using namespace std;
int binarysearch(int arra[], int n, int target) {//function to perform binary search (iterative method)
    int left = 0;//leftmost index of the array
    int right = n - 1; //rightmost index of the array
    while (left <= right) {//continue searching while the left index is less than or equal to the right
        int mid = left + (right - left) / 2; //calculate the middle index
        if (arra[mid] == target) {  //if the middle element is the target
            return mid; //return the index
        } else if (arra[mid] < target) { //if target is greater, search in the right half
            left = mid + 1;
        } else { //if target is smaller, search in the left half
            right = mid - 1;
        }
    }
    return -1; //the target is not found in the array
}
int main() {
    int arra[] = {6, 10, 15, 22,27, 30, 34, 41, 64, 81, 100}; // Declare and initialize a sorted array
    int n = sizeof(arra) / sizeof(arra[0]); // Calculate the number of elements in the array
    int target = 81; //target value to search
    int result = binarysearch(arra, n, target);//call the Binary Search function
    if (result != -1) { //check if the target was found
        cout << "Element found at index " << result <<" Target:"<<target<< endl; //display the index
    } else {
        cout << "Element not found in the array" << endl;
    }
    return 0;
}