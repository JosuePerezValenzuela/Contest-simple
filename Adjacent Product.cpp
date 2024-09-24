#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    vector<int> lista;
    int c;
    cin >> c;
    for (int i = 0; i < c; i++){
        int aux;
        cin >> aux;
        lista.push_back(aux);
    }
    int limite = lista.size() - 1;
    for (int j = 0; j < limite; j++){
        int imp = lista[j] * lista[j + 1];
        cout << imp << " ";
    }
    return 0;
}