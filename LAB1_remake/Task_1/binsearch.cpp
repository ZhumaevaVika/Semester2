#include <iostream>
#include <chrono>
#include <random>

int const N = 200000;


int log_finder(int* a, int sup, int destination){
    int inf = -1;
    while (sup!=inf+1){
        int i = (sup+inf)/2;
        if (a[i]> destination){
            sup = i;
        } else {inf = i;}
    }
    return inf;
}

int main(){
    unsigned seed = 10001;
    std::default_random_engine rng ( seed );
    auto begin = std::chrono::steady_clock::now( );
    for (int j=100;j<=N;j+=N/(200)){
    std::uniform_int_distribution <unsigned> dstr ( 0 , j );
    int* A = new int[N];
            for (int i = 1; i < N - 1; i++) {
                A[i] = i;
        }
    for (int i=0;i!=19;i+=1){
    int random_number = dstr(rng);
    log_finder(A,j+1,random_number);
    }
    auto end = std::chrono::steady_clock::now( );
    auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin );
    std::cout<<j<<","<<(time_span.count()/20)<<"\n";
    delete[] A;
    }
    return 0;
}