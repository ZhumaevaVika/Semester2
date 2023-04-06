#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>

using namespace std;
std::default_random_engine rng(100);

#ifndef N
#define N 50
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

void get_random_speed(Object(&objects)[N*N], int n){
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

void check_neighbours(int real_size, int n, Object(&objects)[N*N]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (abs(objects[i].i-objects[j].i)+abs(objects[i].j-objects[j].j) == 1){
                objects[i].key = 2;
                objects[j].key = 2;
                objects[i].vi = 0;
                objects[i].vj = 0;
                objects[j].vi = 0;
                objects[j].vj = 0;
            }
        }
        if ((objects[i].i == real_size-1)or(objects[i].j == real_size-1)or(objects[i].i == 0)or(objects[i].j == 0)){
            objects[i].key = 2;
            objects[i].vi = 0;
            objects[i].vj = 0;
        }
    }
}

void generate_arr(int real_size, int n, Object(&objects)[N*N]){
    int counter1 = 0;
    for (int k=0; k<n; k++){
        int i = RandInt(0, real_size-1);
        int j = RandInt(0, real_size-1);
        int fl = 0;
        for (int t=0; t<counter1; t++){
            if ((objects[t].i == i)and(objects[t].j == j)){
                fl = 1;
            }
        }
        if (fl == 1){
            k--;
        }
        else{
            Object obj;
            obj.i = i;
            obj.j = j;
            obj.key = 1;
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
            counter1++;
        }
    }
    check_neighbours(real_size, n, objects);
}

void move(int real_size, int n, Object(&objects)[N*N]){
    for (int i=0; i<n; i++){
        objects[i].i += objects[i].vi;
        objects[i].j += objects[i].vj;
        for (int j=0; j<n; j++){
            if (abs(objects[i].i-objects[j].i)+abs(objects[i].j-objects[j].j) == 1){
                if (((objects[i].vi != objects[j].vi) and (objects[i].vj != objects[j].vj))or(objects[j].vi == objects[j].vj)){
                    objects[i].key = 2;
                    objects[j].key = 2;
                    objects[i].vi = 0;
                    objects[i].vj = 0;
                    objects[j].vi = 0;
                    objects[j].vj = 0;
                }
            }
        }
        if ((objects[i].i == real_size-1)or(objects[i].j == real_size-1)or(objects[i].i == 0)or(objects[i].j == 0)){
                objects[i].key = 2;
                objects[i].vi = 0;
                objects[i].vj = 0;
            }
    }
    get_random_speed(objects, n);
}

void print_arr(int(&arr)[N][N]){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    freopen ("data2.txt","w",stdout);
    int step = 5;
    int step2 = 10;
    Object objects[N*N];
        int real_size = N;
        for (int num_obj = 1; num_obj<real_size*real_size; num_obj+=step2){
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
            float result = static_cast<float>(num_obj)/static_cast<float>(real_size*real_size);
            cout << result << ' ' << time_span.count() << ' ' << counter/100 << endl;
        }
    fclose (stdout);
    return 0;
}
