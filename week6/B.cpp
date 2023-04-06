#include <iostream>
#include <string>
using namespace std;

struct Students{
    string name;
    int bal;
};

int main(){
    int N, s = 0;
    cin >> N;
    Students student[N];
    for (int i=0; i<N; i++){
        cin >> student[i].name >> student[i].bal;
        s += student[i].bal;
    }
    cout << s/N;
}