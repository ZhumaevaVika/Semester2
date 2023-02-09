#include <iostream>
using namespace std;

int main() {
    int i=2, p;
    cin >> p;
    while ((p%i != 0)and(i<p/2)){
        i++;
    }
    if (i == p/2){
        cout << "Prime";
    }
    else{
        cout << "Not Prime";
    }
    
    return 0;
}