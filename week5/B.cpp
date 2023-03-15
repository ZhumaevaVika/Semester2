#include <iostream>
using namespace std;


int main(){
    short int* ptr;
    ptr = new short int[10];
    for (int i = 0; i < 10; i++) {
        ptr[i] = i;
        cout << &ptr[i] << ' ';
    }
    cout << endl;

    for (int i=0; i<10; i++){
        cout << ptr[i] << ' ';
    } 
    cout << endl;

    for (int i=0; i<10; i++){
        if (i%2==0){
            *(ptr + i) *= *(ptr + i);
        }
        cout << ptr[i] << ' ';
    } 
    delete[] ptr;
    return 0;
}