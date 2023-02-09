#include <iostream>
using namespace std;

int main() {
    int A=0, B=0, C;
    cin >> C;
    while(A*A + B*B != C){
        B = 0;
        A++;
        while(A*A + B*B < C){
            B++;
         }
         if (A>C){
            cout << "Can't  split into squares" << endl;
            return 0;
         }
    }
    cout << A << ' ' << B;
    return 0;
}