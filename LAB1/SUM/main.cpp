#include <iostream>
#include <chrono>
#include <random>

using namespace std;

#ifndef N
#define N 100000
#endif



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



int sum_search(int (&a)[N], int k, unsigned real_size){
    for(int i = 0; i < real_size; i++){
        for(int j = 0; j < real_size; j++){
            if(j != i and a[j] + a[i] == k){
                return i;
            }
        }   
    }
    return -1;
}

int sum_search_linear(int (&arr)[N], int k, unsigned real_size){
    int l = 0, r = real_size - 1;
    while (l != r){       
        int cursum = arr[l] + arr[r];
        if (cursum < k)
            l++;
        else if (cursum > k)
            r--;
        else
            return l;
    }
    return -1;
}

int time_count(int (&arr)[N], int k, unsigned real_size){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 10000; cnt != 0 ; --cnt)
        sum_search_linear(arr, k, real_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count();
}


int main(){
    freopen ("text_data/N_2.txt","w",stdout);
    int step = 10;
    for (int real_size = 10; real_size < N; real_size=real_size+step){
        if ((real_size == 200)or(real_size == 9000)){
            step = 100;
        }
        else if ((real_size == 5000)or(real_size == 10000)){
            step = 1000;
        }
        int arr[N];
        int k = -1;
        unsigned seed = real_size;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, 1000000);
        for (int j=0; j<real_size; j++){
            arr[j] = dstr(rng);
        }
        shell_sort(arr, real_size);
        cout << time_count(arr, k, real_size) << ' ' << real_size << endl;
    }
    fclose (stdout);
    return 0;
}
