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
    for (int i=0; i<N*2; i++){
        cout << arr[i] << " ";
    }
}

int findLastZero(int (&arr)[N]){
    int l = 0, r = N, mid;
    while (l < r) {
        mid = (l + r) / 2; 
        if (arr[mid] == 1) r = mid;
        else if ((arr[mid] == 0)and(arr[mid+1] == 1)){
            return mid;
        }
        else l = mid + 1;
    }
    r--;
    return 0;
}

int main(){
    int arr[N], ind;
    read_arr(arr);
    ind = findLastZero(arr);
    cout << ind;
    return 0;
}