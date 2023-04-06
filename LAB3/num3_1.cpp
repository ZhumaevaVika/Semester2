#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>

using namespace std;
std::default_random_engine rng(100);

#ifndef N
#define N 100000
#endif

struct Object{
    int i, vi, key;

    Object(){
        i = vi = 0;
        key = 1;
    }
};

int RandInt(int min, int max){
    std::uniform_int_distribution<int> dstr(min, max);
    return dstr(rng);
}

void get_random_speed(Object(&objects)[1], int n){
    srand(time(0));
    for (int k=0; k<n; k++){
        if (objects[k].key != 2){
            int q = rand() % 3 - 1;
                    if (q==0){
                        objects[k].vi = 1;
                    }
                    else if (q==1){
                        objects[k].vi = -1;
                    }
        }
    }
}

void check_neighbours(int real_size, int n, Object(&objects)[1]){
    for (int i=0; i<n; i++){
        if ((objects[i].i == real_size-1)or(objects[i].i == 0)){
            objects[i].key = 2;
            objects[i].vi = 0;
        }
    }
}

void generate_arr(int real_size, int n, Object(&objects)[1]){
    srand(time(0));
    for (int k=0; k<n; k++){
        int i = real_size/2;
        
        Object obj;
        obj.i = i;
        int q = RandInt(0, 1);
        if (q==0){
            obj.vi = 1;
        }
        else if (q==1){
            obj.vi = -1;
        }
        objects[k] = obj;
        
    }
    check_neighbours(real_size, n, objects);
}

void move(int real_size, int n, Object(&objects)[1]){
        objects[0].i += objects[0].vi;
        if ((objects[0].i == real_size-1)or(objects[0].i == 0)){
                objects[0].key = 2;
                objects[0].vi = 0;
            }
    get_random_speed(objects, n);
}

int main(){
    freopen ("data3.txt","w",stdout);
    int num_obj = 1;
    int step = 5;
    Object objects[1];
    for (int real_size = 5; real_size<N; real_size+=step){    

        if (real_size == 500){
            step = 100;
        }
        if (real_size == 10000){
            step = 1000;
        }
        int counter = 0;
        auto begin = std::chrono::steady_clock::now();
        for(unsigned cnt = 1000; cnt != 0 ; --cnt){
            generate_arr(real_size, num_obj, objects);
            int flag = 1;
            while (flag==1){
                flag = 0;
                for (int i = 0; i<num_obj; i++){
                    flag += objects[i].key%2;
                }
                move(real_size, num_obj, objects);
                counter++;
            }
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        cout << real_size << ' ' << counter/10 << endl;
        
    }
    fclose (stdout);
    return 0;
}
