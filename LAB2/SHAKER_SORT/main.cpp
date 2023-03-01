#include <iostream>
#include <chrono>
#include <random>

using namespace std;

#ifndef N
#define N 100000
#endif


void forward_step(int(&arr)[N], unsigned const begin_idx, unsigned const end_idx, int &flag){
    for (int i = begin_idx; i<end_idx; i++){
      if (arr[i]>arr[i + 1]){
        double t = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = t;
        flag = 1;
      }
    }
}

void backward_step(int(&arr)[N], unsigned const begin_idx, unsigned const end_idx, int &flag){
    for (int i = begin_idx; i>end_idx; i--){
      if (arr[i - 1]>arr[i]){
        double t = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = t;
        flag = 1;
      }
    }
}


void shekerSort(int(&arr)[N], unsigned real_size){
  int l = 0, r = real_size - 1;
  int flag = 1;
  while ((l < r) && flag > 0){
    flag = 0;
    //forward_step(arr, l, r, flag);
    //r--;
    backward_step(arr, r, l, flag);
    l++;
  }
}

int time_count(int (&arr)[N], unsigned real_size){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 1000; cnt != 0 ; --cnt)
        shekerSort(arr, real_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return time_span.count();
}

int main(){
    freopen ("LAB2/SHAKER_SORT/text_data/backward_step.txt","w",stdout);
    int step = 100;
    for (int real_size = 100; real_size < N; real_size=real_size+step){
        if (real_size==5000){
            step = 1000;
        }
        int arr[N];
        unsigned seed = real_size;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, real_size-1);
        for (int j=0; j<real_size; j++){
            arr[j] = dstr(rng);
        }

        cout << time_count(arr, real_size) << ' ' << real_size << endl;
    }
    fclose (stdout);
    return 0;
}