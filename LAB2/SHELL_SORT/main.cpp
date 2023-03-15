#include <iostream>
#include <chrono>
#include <random>
#include <cmath>

using namespace std;

#ifndef N
#define N 100000
#endif
#ifndef size0
#define size0 30
#endif

int swap_count;

void get_arr1(int(&arGap)[size0], int real_size){
    int d = real_size;
    for (int i=0; d>=1; i++){
        arGap[i] = d;
        d = d/2;
    }
}

void get_arr2(int(&arGap)[size0], unsigned size){
    for (int i=size; i>0; i--){
        arGap[size-i] = pow(2, i)-1;
    }
}

void reverseArray(int(&arGap)[size0], int size){
    int copy[size];
    for (int i = 0; i < size; i++){
        copy[i] = arGap[size - 1 - i];
    }

    for (int i = 0; i < size; i++){
        arGap[i] = copy[i];
    }
}

int get_arr3(int(&arGap)[size0], unsigned real_size){
    int flag = 0;
    int size=0;
    int fib[25] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393};
    for (int i=0; i<25; i++){
        if (fib[i]<real_size){
            arGap[i] = fib[i];
            size++;
        }
    }
    reverseArray(arGap, size);
    return size;
}

void shell_sort(int (&arr)[N], unsigned real_size){
    int arGap[size0];
    //unsigned size = ceil(log2(real_size));
    //get_arr1(arGap, real_size);
    //get_arr2(arGap, size);
    int size = get_arr3(arGap, real_size);
    for (int gap = arGap[0], iGap = 0; iGap < size; gap = arGap[++iGap]){
        for (int i = gap; i < real_size; ++i){
            int tmp = arr[i];
            int j = i;
            for (; j >= gap && tmp < arr[j-gap]; j -= gap)
                arr[j] = arr[j-gap];
                swap_count++;
            arr[j] = tmp;
        }
    }
}

int time_count(int (&arr)[N], unsigned real_size){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 1000; cnt != 0 ; --cnt)
        shell_sort(arr, real_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count();
}


int main(){
    freopen ("text_data/fib.txt","w",stdout);
    int step = 100;
    for (int real_size = 100; real_size < N; real_size=real_size+step){
        swap_count = 0;
        if (real_size==5000){
            step = 1000;
        }
        int arr[N];
        unsigned seed = real_size;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, real_size-1);
        for (int j=0; j<real_size; j++){
            arr[j] = real_size-j;
        }
        cout << time_count(arr, real_size) << ' ' << swap_count/1000 << ' ' << real_size << endl;
    }
    fclose (stdout);
    return 0;
}


