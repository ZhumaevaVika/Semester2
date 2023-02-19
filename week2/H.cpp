#include <iostream>
using namespace std;

#ifndef N
#define N 2
#endif

#ifndef M
#define M 4
#endif

void read_arr(int (&A)[N][M]){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> A[i][j];
        }
    }
}

void print_AT(int (&AT)[M][N]){
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            cout << AT[i][j] << " ";
        }
        cout << endl;
    }
}

void print_arr(int(&arr)[N+M]){
    for (int i=0; i<N+M; i++){
        cout << arr[i] << " ";
    }
}

void print_transposed(int (&A)[N][M]){
    int AT[M][N];
    for(int j = 0; j < M; ++j){
        for(int i = 0; i < N; ++i){
            AT[j][i] = A[i][j];
        }
    }
    print_AT(AT);
}




int main(){
    int A[N][M];
    read_arr(A);
    print_transposed(A);
    return 0;
}