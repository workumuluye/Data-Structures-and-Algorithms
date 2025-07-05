#include<iostream>
using namespace std;
#define MAX 10
// array of items on which linear search will be conducted.
int list[MAX] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
int interpolation_search(int data){
   int lo = 0;
   int hi = MAX - 1;
   int mid = -1;
   int comparisons = 1;
   int index = -1;
   while(lo <= hi) {
      cout << "Comparison " << comparisons << endl;
      cout << "lo : " << lo << " list[" << lo << "] = " << list[lo] << endl;
      cout << "hi : " << hi << " list[" << hi << "] = " << list[hi] << endl;
      comparisons++;
         // probe the mid point
      mid = lo + (((double)(hi - lo) / (list[hi] - list[lo])) * (data - list[lo]));
      cout << "mid = " << mid;
      // data found
      if(list[mid] == data) {
         index = mid;
         break;
      } else {
         if(list[mid] < data) {      
            // if data is larger, data is in upper half
            lo = mid + 1;
         } else {
            
            // if data is smaller, data is in lower half
            hi = mid - 1;
         }
      }
   }
   cout << "\nTotal comparisons made: " << (--comparisons);
   return index;
}
int main(){  
   //find location of 33
   int location = interpolation_search(33);
   // if element was found
   if(location != -1)
      cout << "\nElement found at location: " << (location+1);
   else
      cout << "Element not found.";
   return 0;
}
