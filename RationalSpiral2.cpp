#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

set<unsigned long long> list;
int i, j;
int denominador = 0;
int numerador = 0;
int den[500005];
int num[500005];
int indice = 0;

int mcd(int a, int b) {
    if(b == 0) return a;
    return mcd(b, a%b);
}

void verfNum(){
    if(!denominador) return;
    static int x, y, maxCM;
    static unsigned long long number;
    x = denominador;
    y = numerador;
    maxCM = mcd(abs(denominador), abs(numerador));
    x /= maxCM;
    y /= maxCM;
    if(x < 0) y = -y, x = -x;
    den[indice] = x; 
    num[indice] = y;
    number = ((long long)x)<<32 | (unsigned)y;
    if(list.find(number) == list.end()) indice++, list.insert(number);
}

int main(){
    int cantPasos = 1;
    char d = 'U';
    while(indice <= 500000){
    for (int aux = 1; aux <= 2 && indice <= 500000; aux++){
        for(int i = 0; i < cantPasos && indice <= 500000; i++){
            switch (d){
                case ('U'):
                    numerador++;
                    break;
                case ('R'):
                    denominador++;
                    break;
                case ('D'):
                    numerador--;
                    break;
                case ('L'):
                    denominador--;
                    break;
                }
            verfNum();
        }
            switch (d){
                case ('U'):
                    d='R';
                    break;
                case ('R'):
                    d='D';
                    break;
                case ('D'):
                    d='L';
                    break;
                case ('L'):
                    d='U';
                    break;
            }
        }
        cantPasos++;
    }
    int aux;
    while(cin >> aux) {
        cout << num[aux] << " / " << den[aux] << endl;
    }
    return 0;
}