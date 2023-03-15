#include <iostream>
#include <chrono>
#include <random>

int const N = 100000;

int linearfinderC(int(&a)[N][2],int destination){
    for (int i=0;i!=N;i+=1){
    if (a[i][0]==destination){
        a[i][1]+=1;
        if (a[i][1]>a[i-1][1]){
        int box0 = a[i-1][0];
        int box1 = a[i-1][1];
        a[i-1][0] = a[i][0];
        a[i-1][1] = a[i][1];
        a[i][0] = box0;
        a[i][1] = box1;
        }
        return(i);
    }}
    return 0;
}

int main(){
    int A[N][2];
    for (int i=0;i!=N-1;i+=1){
        A[i][0]=i;
        A[i][1]=0;}
     unsigned seed = 10001;
    int favorite_elements[N/10];
    for(int i=0;i!=(N/10-1);i+=1){
        favorite_elements[i]=A[i*10][0];
    }
    std::default_random_engine rng ( seed );
    std::cout<<1;
    for (int j=100;j<=N;j+=N/(200)){
    //100 experiments for fixed j
    std::uniform_int_distribution <unsigned> dstr ( 0 , j/10 );
    auto begin = std::chrono::steady_clock::now( );
    for (int i=0;i!=99;i+=1){
    int random_number = favorite_elements[dstr(rng)];
        linearfinderC(A,random_number);
    }

    auto end = std::chrono::steady_clock::now( );

    auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin );
    std::cout<<j<<","<<(time_span.count()/100)<<"\n";
    }
}