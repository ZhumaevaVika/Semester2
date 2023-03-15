#include <iostream>
#include <chrono>
#include <random>

int const N = 200000;

int linearfinder(int* a, int size, int destination) {
    for (int i = 0; i < size; i++) {
        if (a[i] == destination) {
            return i;
        }
    }
    return 0;
}

int main() {

    for (int j = 100; j <= N; j += N / (200)) {
        //тут будет 20 экспериментов для фиксированного j
        auto begin = std::chrono::steady_clock::now();
        int* A = new int[N];
            for (int i = 1; i < N - 1; i++) {
                A[i] = i;
        }
        for (int i = 0; i < 19; i++) {

            linearfinder(A, j, j - 1);
        }

        auto end = std::chrono::steady_clock::now();

        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        std::cout << j << "  " << (time_span.count() / 20) << "\n";
        delete[] A;
    }


    return 0;
}