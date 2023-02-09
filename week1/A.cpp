#include <iostream>
using namespace std;

int rever(int N){
    int M=0;
    while(N != 0){
        M = M*10 + (N%10);
        N = N/10;
    }
    return M;
}

int main(){
    int N;
    cin >> N;
    if (N==rever(N)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}