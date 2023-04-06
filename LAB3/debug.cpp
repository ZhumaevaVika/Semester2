#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef N
#define N 10
#endif

struct Object{
    int i, j, vi, vj, key;

    Object(){
        i = j = vi = vj = 0;
        key = 1;
    }
};

void get_random_speed(Object(&objects)[N*N], int n){
    srand(time(0));
    for (int k=0; k<n; k++){
        if (objects[k].key != 2){
            int q = rand()%4;
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

void check_neighbours(int(&field)[N][N], int n, Object(&objects)[N*N]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (abs(objects[i].i-objects[j].i)+abs(objects[i].j-objects[j].j) == 1){
                objects[i].key = 2;
                objects[j].key = 2;
                objects[i].vi = 0;
                objects[i].vj = 0;
                objects[j].vi = 0;
                objects[j].vj = 0;
                field[objects[i].i][objects[i].j] = 2;
                field[objects[j].i][objects[j].j] = 2;
            }
        }
        if ((objects[i].i == N-1)or(objects[i].j == N-1)or(objects[i].i == 0)or(objects[i].j == 0)){
            objects[i].key = 2;
            objects[i].vi = 0;
            objects[i].vj = 0;
            field[objects[i].i][objects[i].j] = 2;
        }
    }
}

void generate_arr(int(&field)[N][N], int n, Object(&objects)[N*N]){
    srand(time(0));
    for (int k=0; k<n; k++){
        int i = rand()%N;
        int j = rand()%N;
        if (field[i][j] == 1){
            k--;
        }
        else{
            field[i][j] = 1;
            Object obj;
            obj.i = i;
            obj.j = j;
            int q = rand()%4;
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
    }
    check_neighbours(field, n, objects);
}

void move(int(&field)[N][N], int n, Object(&objects)[N*N]){
    for (int i=0; i<n; i++){
        field[objects[i].i][ objects[i].j] = 0;
        objects[i].i += objects[i].vi;
        objects[i].j += objects[i].vj;
        field[objects[i].i][ objects[i].j] = 1;
        for (int j=0; j<n; j++){
            if (abs(objects[i].i-objects[j].i)+abs(objects[i].j-objects[j].j) == 1){
                if (((objects[i].vi != objects[j].vi) and (objects[i].vj != objects[j].vj))or(objects[j].vi == objects[j].vj)){
                    objects[i].key = 2;
                    objects[j].key = 2;
                    objects[i].vi = 0;
                    objects[i].vj = 0;
                    objects[j].vi = 0;
                    objects[j].vj = 0;
                    field[objects[i].i][objects[i].j] = 2;
                    field[objects[j].i][objects[j].j] = 2;
                }
            }
        }
        if ((objects[i].i == N-1)or(objects[i].j == N-1)or(objects[i].i == 0)or(objects[i].j == 0)){
                objects[i].key = 2;
                objects[i].vi = 0;
                objects[i].vj = 0;
                field[objects[i].i][objects[i].j] = 2;
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
    int field[N][N] = {0};
    int num_obj;
    int flag = 1;
    int test;
    cin >> num_obj;
    Object objects[N*N];
    generate_arr(field, num_obj, objects);
    print_arr(field);
    while (flag){
        flag = 0;
        for (int i = 0; i<num_obj; i++){
            flag += objects[i].key%2;
        }
        move(field, num_obj, objects);
        cout << endl;
        print_arr(field);
        cin >> test;
    }
}
