#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b;
    if (a%b == a){
        c = a;
        a = b;
        b = c;
    }
    while (a%b != 0){
        a = a-b;
        if (a%b == a){
        c = a;
        a = b;
        b = c;
        }
    }
    cout << b << endl;
    return 0;
}