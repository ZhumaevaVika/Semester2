#include <iostream>
#include <chrono>
#include <random>

int const N = 100000;

int linearfinderA(int* a, int destination){
    for (int i=0;i!=N;i+=1){
    if (a[i]==destination){
        return i;
        int box = a[0];
        a[0] = a[i];
        a[i] = box;
    }}
    return 0;
}

int main(){
    unsigned seed = 10001;
    int favorite_elements[N/10];
    int* A = new int[N];
            for (int i = 1; i < N - 1; i++) {
                A[i] = i;
        }
    for(int i=0;i!=(N/10-1);i+=1){
        favorite_elements[i]=A[i*10];
    }
    std::default_random_engine rng ( seed );
    for (int j=100;j<=N;j+=N/(200)){
    //100 experiments for fixed j
    std::uniform_int_distribution <unsigned> dstr ( 0 , (j/10) );
    auto begin = std::chrono::steady_clock::now( );
    for (int i=0;i!=99;i+=1){
    int random_element = favorite_elements[dstr(rng)];
        linearfinderA(A,random_element);
    }

        auto end = std::chrono::steady_clock::now( );

        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin );
        std::cout<<j<<","<<(time_span.count()/100)<<"\n";
    }
    delete[] A;
    return 0;
}