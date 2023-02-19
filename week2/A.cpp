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

void reverseArray(int(&arr)[N]){
    int copy[N];
    for (int i = 0; i < N; i++){
        copy[i] = arr[N - 1 - i];
    }

    for (int i = 0; i < N; i++){
        arr[i] = copy[i];
    }
}

int main(){
    int arr[N];
    read_arr(arr);
    reverseArray(arr);
    print_arr(arr);
    return 0;

}