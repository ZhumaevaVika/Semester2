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
    int i, j, vi, vj, key;

    Object(){
        i = j = vi = vj = 0;
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
            int q = RandInt(0, 3);
                    if (q==0){
                        objects[k].vi = 1;
                        objects[k].vj = 0;
                    }
                    else if (q==1){
                        objects[k].vi = -1;
                        objects[k].vj = 0;
                    }
                    else if (q==2){
                        objects[k].vi = 0;
                        objects[k].vj = 1;
                    }
                    else{
                        objects[k].vi = 0;
                        objects[k].vj = -1;
                    }
        }
    }
}

void check_neighbours(int real_size, int n, Object(&objects)[1]){
    for (int i=0; i<n; i++){
        if ((objects[i].i == real_size-1)or(objects[i].j == real_size-1)or(objects[i].i == 0)or(objects[i].j == 0)){
            objects[i].key = 2;
            objects[i].vi = 0;
            objects[i].vj = 0;
        }
    }
}

void generate_arr(int real_size, int n, Object(&objects)[1]){
    srand(time(0));
    for (int k=0; k<n; k++){
        int i = real_size/2;
        int j = real_size/2;
        
        Object obj;
        obj.i = i;
        obj.j = j;
        int q = RandInt(0, 3);
        if (q==0){
            obj.vi = 1;
            obj.vj = 0;
        }
        else if (q==1){
            obj.vi = -1;
            obj.vj = 0;
        }
        else if (q==2){
            obj.vi = 0;
            obj.vj = 1;
        }
        else{
            obj.vi = 0;
            obj.vj = -1;
        }
        objects[k] = obj;
        
    }
    check_neighbours(real_size, n, objects);
}

void move(int real_size, int n, Object(&objects)[1]){
    for (int i=0; i<n; i++){
        objects[i].i += objects[i].vi;
        objects[i].j += objects[i].vj;
        if ((objects[i].i == real_size-1)or(objects[i].j == real_size-1)or(objects[i].i == 0)or(objects[i].j == 0)){
                objects[i].key = 2;
                objects[i].vi = 0;
                objects[i].vj = 0;
            }
    }
    get_random_speed(objects, n);
}

void print_arr(int(&arr)[N][N], int real_size){
    for (int i=0; i<real_size; i++){
        for (int j=0; j<real_size; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    freopen ("data1.txt","w",stdout);
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
            }
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        cout << real_size << ' ' << time_span.count() << endl;
        
    }
    fclose (stdout);
    return 0;
}
