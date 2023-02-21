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

int findUnique(int (&arr)[N]){
    if(N == 1){
        return arr[0];
    }
    int el = arr[0];
    for(int i = 1; i < N; i++){
        el = el ^ arr[i];
    }
    return el;
}

int main(){
    int arr[N], ind;
    read_arr(arr);
    cout << findUnique(arr);
    return 0;
}