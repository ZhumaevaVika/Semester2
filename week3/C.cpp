#include <iostream>
using namespace std;

#ifndef N
#define N 6
#endif

void read_arr(int(&arr)[N]){
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
}

void print_arr(int(&arr)[N]){
    for (int i=0; i<N; i++){
        cout << arr[i] << " ";
    }
}

void rev(int(&arr)[N], int i) {
   int temp, st = 0;
   while (st < i) {
      temp = arr[st];
      arr[st] = arr[i];
      arr[i] = temp;
      st++;
      i--;
   }
}

int maxIndex(int(&arr)[N], int n) {
   int index, i;
   for (index = 0, i = 0; i < n; ++i){
      if (arr[i] > arr[index]) {
         index = i;
      }
   }
   return index;
}

void pancakeSort(int(&arr)[N]) {
   for (int size = N; size > 1; size--) {
      int index = maxIndex(arr, size);
      if (index != size-1) {
         rev(arr, index);
         rev(arr, size-1);
      }
   }
}

int main(){
    int arr[N];
    read_arr(arr);
    pancakeSort(arr);
    print_arr(arr);
    return 0;
}