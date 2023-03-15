#include <iostream>
using namespace std;

void input_array(int* ptr, size_t N) {
    for (size_t i = 0; i < N; i++) {
        cin >> ptr[i];
    }
}

void reverse(int* ptr, size_t N) {
    for (size_t i = 0; i < N/2; i++) {
        int temp = ptr[i];
        ptr[i] = ptr[N-1-i];
        ptr[N-1-i] = temp;
    }
}

void print(const int* ptr, size_t N) {
    for (size_t i = 0; i < N; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main() {
    size_t N = 0;
    cin >> N;
    int* ptr = new int[N];
    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);
    delete[] ptr;
    return 0;
}