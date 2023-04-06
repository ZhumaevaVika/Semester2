#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>

using namespace std;
std::default_random_engine rng(100);

#ifndef N
#define N 200
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

void get_random_speed(Object(&objects)[N*N], int n){
    srand(time(0));
    for (int k=0; k<n; k++){
        if (objects[k].key != 2){
            int q = RandInt(0, 1);
                    if (q==0){
                        objects[k].vi = 1;
                    }
                    else if (q==1){
                        objects[k].vi = -1;
                    }
        }
    }
}

void check_neighbours(int real_size, int n, Object(&objects)[N*N]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (abs(objects[i].i-objects[j].i) == 1){
                objects[i].key = 2;
                objects[j].key = 2;
                objects[i].vi = 0;
                objects[j].vi = 0;
            }
        }
        if ((objects[i].i == real_size-1)or(objects[i].i == 0)){
            objects[i].key = 2;
            objects[i].vi = 0;
        }
    }
}

void generate_arr(int real_size, int n, Object(&objects)[N*N]){
    int counter1 = 0;
    for (int k=0; k<n; k++){
        int i = RandInt(0, real_size-1);
        int fl = 0;
        for (int t=0; t<counter1; t++){
            if (objects[t].i == i){
                fl = 1;
            }
        }
        if (fl == 1){
            k--;
        }
        else{
            Object obj;
            obj.i = i;
            obj.key = 1;
            int q = RandInt(0, 1);
            if (q==0){
                obj.vi = 1;
            }
            else if (q==1){
                obj.vi = -1;
            }
            objects[k] = obj;
            counter1++;
        }
    }
    check_neighbours(real_size, n, objects);
}

void move(int real_size, int n, Object(&objects)[N*N]){
    for (int i=0; i<n; i++){
        objects[i].i += objects[i].vi;
        for (int j=0; j<n; j++){
            if (abs(objects[i].i-objects[j].i) == 1){
                if (objects[i].vi != objects[j].vi){
                    objects[i].key = 2;
                    objects[j].key = 2;
                    objects[i].vi = 0;
                    objects[j].vi = 0;
                }
            }
        }
        if ((objects[i].i == real_size-1)or(objects[i].i == 0)){
                objects[i].key = 2;
                objects[i].vi = 0;
            }
    }
    get_random_speed(objects, n);
}

int main(){
    freopen ("data4.txt","w",stdout);
    int step2 = 1;
    Object objects[N*N];
        int real_size = N;
        for (int num_obj = 1; num_obj<real_size; num_obj+=step2){
            int counter = 0;
            auto begin = std::chrono::steady_clock::now();
            for(unsigned cnt = 100; cnt != 0 ; --cnt){
                int flag = 1;
                generate_arr(real_size, num_obj, objects);
                while (flag>=1){
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
            float result = static_cast<float>(num_obj)/static_cast<float>(real_size);
            cout << result << ' ' << time_span.count() << ' ' << counter/100 << endl;
        }
    fclose (stdout);
    return 0;
}
