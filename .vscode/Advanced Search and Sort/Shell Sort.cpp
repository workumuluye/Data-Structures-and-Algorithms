#include<iostream>
using namespace std;
void shellSort(int *arr, int n){
   int gap, j, k;
   for(gap = n/2; gap > 0; gap = gap / 2) { //initially gap = n/2, decreasing by gap /2
      for(j = gap; j<n; j++) {
         for(k = j-gap; k>=0; k -= gap) {
            if(arr[k+gap] >= arr[k])
               break;
            else {
               int temp;
               temp = arr[k+gap];
               arr[k+gap] = arr[k];
               arr[k] = temp;
            }
         }
      }
   }
}
int main(){
   int n;
   n = 5;
   int arr[5] = {33, 45, 62, 12, 98}; // initialize the array
   cout << "Array before Sorting: ";
   for(int i = 0; i<n; i++)
      cout << arr[i] << " ";
   cout << endl;
   shellSort(arr, n);
   cout << "Array after Sorting: ";
   for(int i = 0; i<n; i++)
      cout << arr[i] << " ";
   cout << endl;
}
