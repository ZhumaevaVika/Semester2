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

void doubleSelectSort(int(&arr)[N]){
    for (int i = 0, j = N - 1; i < j; i++, j--){
        int min = arr[i], max = arr[i];
        int min_i = i, max_i = i;
        for (int k = i; k <= j; k++){
            if (arr[k] > max){
                max = arr[k];
                max_i = k;
            } else if (arr[k] < min){
                min = arr[k];
                min_i = k;
            }
        }
         swap(arr[i], arr[min_i]);
        if (arr[min_i] == max)
            swap(arr[j], arr[min_i]);
        else
            swap(arr[j], arr[max_i]);
    }
}



int main(){
    int arr[N];
    read_arr(arr);
    doubleSelectSort(arr);
    print_arr(arr);
    return 0;
}