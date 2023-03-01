#include <iostream>
#include <chrono>
#include <random>
#include <string>

using namespace std;

#ifndef N
#define N 100000
#endif

void read_arr(int(&arr)[N]){
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
}

void print_arr(int(&arr)[N], unsigned real_size){
    for (int i=0; i<real_size; i++){
        cout << arr[i] << " ";
    }
}

void shell_sort(int (&arr)[N], unsigned real_size){
    int arGap[16] = { 510774, 227011, 100894, 44842, 19930, 8858, 3937, 1750, 701, 301, 132, 57, 23, 10, 4, 1 };

    for (int gap = arGap[0], iGap = 0; iGap < 16; gap = arGap[++iGap])
        for (int i = gap; i < real_size; ++i) {
            int tmp = arr[i];
            int j = i;
            for (; j >= gap && tmp < arr[j-gap]; j -= gap)
                arr[j] = arr[j-gap];
            arr[j] = tmp;
        }
}





int main(){
    for (int real_size = 1000; real_size < N; real_size=real_size+1000){
        int arr[N];
        int k = -1;
        unsigned seed = real_size;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, 100000000);
        for (int j=0; j<real_size; j++){
            arr[j] = dstr(rng);
        }
        shell_sort(arr, real_size);
        print_arr(arr, real_size);
    }
}