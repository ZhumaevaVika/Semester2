#include <iostream>
using namespace std;

int main(){
    int N, b, a, mi=0, ma=0;
    cin >> N;
    cin >> a;
    while(N-1>0){
        cin >> b;
        if (b>a){
            ma++;
        }
        else{
            mi++;
        }
        a=b;
        N--;
    }
    if (ma>mi){
        cout << "MAX";
    }
    else{
        cout << "MIN";
    }
}