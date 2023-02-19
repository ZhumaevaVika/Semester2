#include <iostream>
using namespace std;

#ifndef N
#define N 3
#endif

void read_arr(int(&arr)[N]){
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
}

void print_arr(int(&arr)[N*2]){
    for (int i=0; i<N*2; i++){
        cout << arr[i] << " ";
    }
}

void mergeArrays(int (&arr1)[N], int (&arr2)[N], int (&arr)[2*N]){
    for (int i=0; i<N; i++){
        arr[i] = arr1[i];
        arr[i+N] = arr2[i];
    }

    for (int i=0; i<2*N; i++){
        for (int j=0; j<2*N-1; j++){
            if (arr[j]>arr[j+1]){
                auto tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main(){
    int arr1[N], arr2[N], arr[2*N];
    read_arr(arr1);
    read_arr(arr2);
    mergeArrays(arr1, arr2, arr);
    print_arr(arr);
    return 0;
}