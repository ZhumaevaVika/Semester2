#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c, d, x1, x2;
    cin >> a >> b >> c;
    if ((a==0)and(b==0)){
        cout << "None";
    }
    else if ((a==0)and(b!=0)){
        cout << -c/b;
    }
    else{
        d = b*b - 4*a*c;
        if (d<0){
            cout << "None";
        }
        else{
            x1  = (-b + sqrt(d))/(2*a);
            x2  = (-b - sqrt(d))/(2*a);
            cout << x1  << " " << x2;
        }
    }
    return 0;
}
