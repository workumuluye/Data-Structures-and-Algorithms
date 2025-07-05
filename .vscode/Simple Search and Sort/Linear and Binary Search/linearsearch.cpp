#include <iostream> 
using namespace std; 
int linearsearch(int arra[], int n, int target) { //function to perform Linear Search
    for (int i = 0; i < n; i++) { //loop through each element of the array
        if (arra[i] == target) { //check if the current element matches the target
            return i;//return the index if found
        }
    }
    return -1; //the target is not found in the array
}
int main() {
    int arra[] = {4, 64, 10, 34, 45, 50,25, 80};//declare and initialize an array
    int n = sizeof(arra) / sizeof(arra[0]);//calculate the number of elements in the array
    int target = 25;//target value to search
    int result = linearsearch(arra, n, target);//call the Linear Search function
    if (result != -1) { //check if the target was found
        cout << "Element found at index " << result <<" Target: "<< target<< endl;//display the index
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
