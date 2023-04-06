#include <iostream>
using namespace std;

struct vectorN {
    int N;
    int* coords;

    vectorN(int d, int* c) {
        N = d;
        coords = new int[N];
        for (int i = 0; i < N; i++) {
            coords[i] = c[i];
        }
    }

    vectorN operator+(const vectorN& other) const {
        int* result_coords = new int[N];
        for (int i = 0; i < N; i++) {
            result_coords[i] = coords[i] + other.coords[i];
        }
        vectorN result(N, result_coords);
        delete[] result_coords;
        return result;
    }
};

void print_vector(const vectorN& v) {
        cout << v.N << " ";
        for (int i = 0; i < v.N; i++) {
            cout << v.coords[i] << " ";
        }
        cout << endl;
}

int main() {
    int N;
    cin >> N;

    int* coords1 = new int[N];
    int* coords2 = new int[N];
    int* coords3 = new int[N];


    for (int i = 0; i < N; i++) {
        cin >> coords1[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> coords2[i];
    }

    vectorN v1(N, coords1);
    vectorN v2(N, coords2);
    vectorN v3(N, coords3);

    v3 = v1+v2;
    print_vector(v3);
    
    delete[] coords1;
    delete[] coords2;
    delete[] coords3;

    return 0;
}