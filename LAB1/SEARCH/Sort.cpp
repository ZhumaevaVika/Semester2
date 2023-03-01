#include <iostream>
#include <chrono>
#include <random>

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

int perebor(int (&arr)[N], int k, unsigned real_size){
    for(int i=0; i<real_size; i++){
        if (arr[i] == k){
            return i;
        }
    }
    return -1;
}

int bin_search(int (&arr)[N], int k, unsigned real_size){
    int l = 0, r = real_size, mid;
    while (true){
        mid = (l + r) / 2;
        if (k < arr[mid])
            r = mid - 1;
        else if (k > arr[mid])
            l = mid + 1;
        else
            return mid;
        
        if (l > r)
            return -1;
    }
}

int time_count(int (&arr)[N], int k, unsigned real_size){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 1000000; cnt != 0 ; --cnt)
        //perebor(arr, k, real_size);
        bin_search(arr, k, real_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count();
}


int main(){
    freopen ("text_data/mean_binsearch2.txt","w",stdout);
    int step = 100;
    for (int real_size = 100; real_size < N; real_size=real_size+step){
        if (real_size == 5000){
            step = 1000;
        }
        int arr[N];
        //int k = -1; // worst
        unsigned seed = real_size;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, real_size-1);
        for (int j=0; j<real_size; j++){
            arr[j] = dstr(rng);
        }
        // mean
        int sum_time = 0;
        shell_sort(arr, real_size);
        for (int q=0; q<10; q++){
            int k = arr[dstr(rng)];
            int time = time_count(arr, k, real_size);
            sum_time += time;
        }


        //shell_sort(arr, real_size);
        //cout << time_count(arr, k, real_size) << ' ' << real_size << endl;
        cout << sum_time/10 << ' ' << real_size << endl;
    }
    fclose (stdout);
    return 0;
}