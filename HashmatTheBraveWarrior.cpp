#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    long long c1, c2;
    while(cin >> c1 >> c2){
        long long imprimir = abs(c1 - c2);
        cout << imprimir << endl;
    }
    return 0;
}