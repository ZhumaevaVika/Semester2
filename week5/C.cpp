#include <iostream>
using namespace std;

int main() {
    int* ptr = new int[1];
    int num, size = 1;
    cin >> num;
    ptr[0] = num;
    while (num != 0) {
        cin >> num;
        if (size == 1 && num != 0) {
            int* new_ptr = new int[2];
            new_ptr[0] = ptr[0];
            new_ptr[1] = num;
            delete[] ptr;
            ptr = new_ptr;
            size = 2; 
        }
        else if (num != 0) {
            int* new_ptr = new int[size + 1]; 
            for (int i = 0; i < size; i++) {
                new_ptr[i] = ptr[i];
            }
            new_ptr[size] = num;
            delete[] ptr;
            ptr = new_ptr;
            size++;
        }
    }

    for (int i = 0; i < size - 1; i++) { 
        cout << ptr[i] - ptr[i+1] << " ";
    }

    delete[] ptr;
    return 0;
}