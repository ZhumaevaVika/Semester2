#include <iostream>
using namespace std;

#ifndef N
#define N 5
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

void selectSort(int (&arr)[N]){
    int tmp, min;
    for (int i=0; i<N-1; i++){
        tmp = arr[i];
        min = i;
        for (int j=i+1; j<N; j++){
            if (arr[j]<arr[min]){
                min = j;
            }
        }
        if (min!=i){
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}


int main(){
    int arr[N];
    read_arr(arr);
    selectSort(arr);
    print_arr(arr);
    return 0;
}