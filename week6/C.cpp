#include <iostream>
#include <string>
using namespace std;

struct Time{
    int hour;
    int min;
    int sec;
};

int main(){
    Time begin, end, fin;
    cin >> begin.hour >> begin.min >> begin.sec;
    cin >> end.hour >> end.min >> end.sec;
    fin.sec = (begin.sec + end.sec)%60;
    fin.min = (begin.min + end.min + (begin.sec + end.sec)/60)%60;
    fin.hour = (begin.hour + end.hour + (begin.min + end.min + (begin.sec + end.sec)/60)/60)%24;
    cout << fin.hour << ':' << fin.min << ':' << fin.sec << endl;
}