#include <iostream>
using namespace std;


int main(){
    double *ptr;
    *ptr = 0;
    cout << ptr << ' ' << *ptr << endl;
    ptr = ptr-3;
    cout << ptr << ' ' << *ptr << endl;
    ptr = ptr+5;
    cout << ptr << ' ' << *ptr << endl;
    return 0;
}