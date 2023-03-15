#include <iostream>
#include <chrono>
#include <random>

using namespace std;

#ifndef N
#define N 100000
#endif
int swap_count = 0;


int getNextGap(int gap){
    gap = (gap*10)/13;
    if (gap < 1)
        return 1;
    return gap;
}
  
void combSort(int (&arr)[N], unsigned real_size){
    int gap = real_size;
    bool swapped = true;
    while (gap != 1 || swapped == true){
        gap = getNextGap(gap);
        swapped = false;
          for (int i=0; i<real_size-gap; i++){
            if (arr[i] > arr[i+gap]){
                swap(arr[i], arr[i+gap]);
                swapped = true;
                swap_count++;
            }
        }
    }
}

int time_count(int (&arr)[N], unsigned real_size){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 10000; cnt != 0 ; --cnt)
        combSort(arr, real_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count();
}

int main(){
    freopen ("data.txt","w",stdout);
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

        cout << time_count(arr, real_size) << ' ' << swap_count << ' ' << real_size << endl;
    }
    fclose (stdout);
    return 0;
}
