#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef N
#define N 5
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

void check_neighbours1(int(&field)[N][N], int n, Object(&objects)[N*N], int i, int j){
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

void check_border(int(&field)[N][N], int n, Object(&objects)[N*N], int i){
    if ((objects[i].i == N-1)or(objects[i].j == N-1)or(objects[i].i == 0)or(objects[i].j == 0)){
            objects[i].key = 2;
            objects[i].vi = 0;
            objects[i].vj = 0;
            field[objects[i].i][objects[i].j] = 2;
        }
}

void generate_arr(int(&field)[N][N], int n, Object(&objects)[N*N], int faza){
    Object obj1;
    Object obj2;
    if (faza == 0){
    obj1.i = 3;
    obj1.j = 1;
    obj1.vi = -1;
    field[3][1] = 1;

    obj2.i = 2;
    obj2.j = 2;
    obj2.vj = -1;
    objects[0] = obj1;
    objects[1] = obj2;
    field[2][2] = 1;
    }
    else if (faza == 1){
        obj1.i = 3;
        obj1.j = 1;
        obj1.vi = -1;
        field[3][1] = 1;

        obj2.i = 2;
        obj2.j = 2;
        obj2.vi = -1;
        objects[0] = obj1;
        objects[1] = obj2;
        field[2][2] = 1;
    }
    else if (faza == 2){
        obj1.i = 3;
        obj1.j = 1;
        obj1.vi = -1;
        field[3][1] = 1;

        obj2.i = 1;
        obj2.j = 2;
        obj2.vi = 1;
        objects[0] = obj1;
        objects[1] = obj2;
        field[1][2] = 1;
    }
    else if (faza == 3){
        obj1.i = 3;
        obj1.j = 1;
        obj1.vi = -1;
        field[3][1] = 1;

        obj2.i = 2;
        obj2.j = 2;
        obj2.vi = 1;
        objects[0] = obj1;
        objects[1] = obj2;
        field[2][2] = 1;
    }
    else if (faza == 4){
        obj1.i = 3;
        obj1.j = 1;
        obj1.vj = 1;
        field[3][1] = 1;

        obj2.i = 1;
        obj2.j = 2;
        obj2.vi = 1;
        objects[0] = obj1;
        objects[1] = obj2;
        field[1][2] = 1;
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            check_neighbours1(field, n, objects, i, j);
        }
    }
    for (int i=0; i<n; i++){
        check_border(field, n, objects, i);
    }
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
    int num_obj = 2;
    int flag = 1;
    int test;
    int faza;
    cin >> faza;
    Object objects[N*N];
    generate_arr(field, num_obj, objects, faza);
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
