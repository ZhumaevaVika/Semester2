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

void moveNegativeToEnd(int (&arr)[N]){
    
}

int main(){
    int arr[N];
    read_arr(arr);
    moveNegativeToEnd(arr);
    print_arr(arr);
    return 0;
}