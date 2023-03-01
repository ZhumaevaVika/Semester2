#include <iostream>
#include <chrono>
#include <random>

using namespace std;

#ifndef N
#define N 10000
#endif


void selectSort(int (&arr)[N], unsigned real_size){
    int tmp, min;
    for (int i=0; i < real_size-1; i++){
        tmp = arr[i];
        min = i;
        for (int j=i+1; j < real_size; j++){
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

void doubleSelectSort(int(&arr)[N], unsigned real_size){
    for (int i = 0, j = real_size - 1; i < j; i++, j--){
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

int time_count(int (&arr)[N], unsigned real_size, int flag){
    auto begin = std::chrono::steady_clock::now();
    if (flag==0){
        for(unsigned cnt = 100; cnt != 0 ; --cnt)
            selectSort(arr, real_size);
    }
    else{
        for(unsigned cnt = 100; cnt != 0 ; --cnt)
            doubleSelectSort(arr, real_size);
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count();
}


int main(){
    freopen ("text_data.txt","w",stdout);
    int step = 10;
    for (int real_size = 10; real_size < N; real_size=real_size+step){
        if (real_size == 500){
            step = 100;
        }
        int arr[N];
        unsigned seed = real_size;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, 100000000);
        for (int j=0; j<real_size; j++){
            arr[j] = dstr(rng);
        }
        cout << time_count(arr, real_size, 0) << ' ' << time_count(arr, real_size, 1) << ' ' << real_size << endl;
    }
    fclose (stdout);
    return 0;
}