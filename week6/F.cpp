#include <iostream>
using namespace std;

struct Complex {
    int re;
    int im;
};

Complex complexMul(const Complex& lhs, const Complex& rhs){
    Complex c;
    c.re = lhs.re*rhs.re - lhs.im*rhs.im;
    c.im = lhs.re*rhs.im + lhs.im*rhs.re;
    return c;
}


int main(){
    Complex a, b;
    cin >> a.re >> a.im >> b.re >> b.im;
    cout << complexMul(a, b).re << ' ' << complexMul(a, b).im << endl;
}