#include <iostream>
using namespace std;

int nul(int a){
    int i=5, s=0;
    while(i<=a){
        s+=a/i;
        i*=5;
    }
    return s;
}

int main(){
    int a;
    cin >> a;
    cout << nul(a);
    return 0;
}