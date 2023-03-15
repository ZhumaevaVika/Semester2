#include <iostream>
#include <chrono>
#include <random>

using std::cout;
using std::cin;
using std::endl;

const int MAX_SZ = 1e5;
int a[MAX_SZ];
int b[MAX_SZ];
int c[MAX_SZ];
int pick[MAX_SZ];
int cnt[MAX_SZ];

bool mA(int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
            if (i != 0) 
                std::swap(a[i], a[0]);
            return true;
        }
    }
    return false;
}

bool mB(int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (b[i] == x) {
            if (i > 0)
                std::swap(b[i], b[i - 1]);
            return true;
        }
    }
    return false;
}

bool mC(int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (c[i] == x) {
            cnt[c[i]]++;
            if (i > 0 && cnt[c[i]] > cnt[c[i - 1]])
                std::swap(c[i], c[i - 1]);
            return true;
        }
    }
    return false;
}


bool mN(int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (pick[i] == x) 
            return true;
    }
    return false;
}

    
double TIME(int n, char ty, bool good_distr=true) {
    // good_distr = true;
    int amount = std::min(n, 100000);
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    int to = n;
    if (!good_distr) {
        to = n / 10; // неравномерное распределение данных
    }
    std::uniform_int_distribution <unsigned> dstr(0, to);
    auto begin = std::chrono::steady_clock::now();
    for (unsigned counter = amount; counter > 0; --counter) {
        int x = pick[dstr(rng)]; // pick a random number from range(that is sorted)
        // cout << x << endl;
        if (ty == 'A') 
            mA(n, x);
        if (ty == 'B')
            mB(n, x);
        if (ty == 'C')
            mC(n, x);
        if (ty == 'N')
            mN(n, x);
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    double time_taken = time_span.count(); // how long did the entire amount take?;    
    return (double)time_taken / (double)amount;
}
void result(int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = i;
        b[i] = i;
        c[i] = i;
        cnt[i] = 0;
        pick[i] = i;
    }
    double A, B, C, N;
    A = B = C = N = 0.0;
    A = TIME(n, 'A', false);
    B = TIME(n, 'B', false);
    C = TIME(n, 'C', false); // смотрим на неравномерное распределение
    for (int i = 0; i < n; ++i) {
        a[i] = i;
        b[i] = i;
        c[i] = i;
        cnt[i] = 0;
        pick[i] = i;
    }
    N = TIME(n, 'A', true); // обычный случай. с C/B/A 
    cout << n << " " << A << " " << B << " " << C << " " << N << "\n";
    return;
}


int main() {   
    freopen ("data.txt","w",stdout);
    // std::vector<int> n_vals(4);
    // n_vals = {100}; //100 * 4^k, чтобы хорошо был виден бинпоиск тк он ведет себя как log2
    cout.precision(10);
    for (auto n = 2000; n <= 100000; n *= 1.2){
        result(n); 
    }
    fclose (stdout);
    return 0;
}


