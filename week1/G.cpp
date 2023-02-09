#include <iostream>
using namespace std;

int main(){
    int N, b, a, c, mi=0, ma=0;
    cin >> N;
    cin >> a >> b;
    while(N-2>0){
        cin >> c;
        if ((b>=a)and(b>=c)){
            ma++;
        }
        else if ((b<=a)and(b<=c)){
            mi++;
        }
        a = b;
        b = c;
        N--;
    }
    if (ma>mi){
        cout << "MAX";
    }
    else if (mi>ma){
        cout << "MIN";
    }
    else{
        cout << "EQUAL";
    }
    return 0;
}