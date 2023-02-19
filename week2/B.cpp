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

void shiftRight(int (&arr)[N]){
    int copy[2*N];
    for (int i=0; i<N; i++){
        copy[i] = arr[i];
        copy[i+N] = arr[i];
    }

    for (int i=0; i<N; i++){
        arr[i] = copy[N+i-1];
    }
}

int main(){
    int arr[N];
    read_arr(arr);
    shiftRight(arr);
    print_arr(arr);
    return 0;
}