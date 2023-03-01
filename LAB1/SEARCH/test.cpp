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

void selectSort(int (&arr)[N], unsigned real_size){
    int tmp, min;
    for (int i=0; i<real_size-1; i++){
        tmp = arr[i];
        min = i;
        for (int j=i+1; j<real_size; j++){
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
    for(unsigned cnt = 10000; cnt != 0 ; --cnt)
        perebor(arr, k, real_size);
        //bin_search(arr, k, real_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count();
}


int main(){
    freopen ("text_data/mean_perebor1.txt","w",stdout);
    for (int real_size = 1000; real_size < N; real_size=real_size+1000){
        int arr[N];
        int k;
        unsigned seed = real_size;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, 100000000);
        for (int j=0; j<real_size; j++){
            arr[j] = dstr(rng);
        }
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<std::mt19937::result_type> dist(0,real_size-1);

        k = arr[dist(rng)];
        // selectSort(arr, real_size);
        cout << time_count(arr, k, real_size) << ' ' << real_size << endl;
    }
    fclose (stdout);
}