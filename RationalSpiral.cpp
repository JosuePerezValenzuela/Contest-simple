#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

std::pair<int, int> decimal_a_fraccion(double decimal) {
    const double EPSILON = 1e-9;
    int signo = (decimal < 0) ? -1 : 1;
    decimal = fabs(decimal);
    
    int numerador = static_cast<int>(decimal);
    int denominador = 1;
    
    while (fabs(decimal - numerador / static_cast<double>(denominador)) > EPSILON) {
        denominador++;
        numerador = static_cast<int>(decimal * denominador);
    }
    
    return std::make_pair(signo * numerador, denominador);
}

bool verfNum(double num, int denominador, vector<double>&list){
    bool resp;
    if(denominador == 0){
        resp = true;
    }else{
        resp = find(list.begin(), list.end(), num) != list.end();
    }
    return resp;
}

int main(){
    vector <double> list;
    int numerador = 0;
    int denominador = 0;
    char d = 'U';
    int n;
    int cantPasos = 1;
    int tamList = 0;
    while(cin >> n){
        int nn = n + 1;
        while (tamList < nn){
            for (int aux = 1; aux <= 2; aux++){
                for(int i = 0; i < cantPasos; i++){
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
                    double num = static_cast<double>(numerador)/denominador;
                    if(verfNum(num, denominador, list) == false){
                        list.push_back(num);
                        tamList++;
                    }
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
        auto aux = decimal_a_fraccion(list[n]);
        std::cout << aux.first << " / " << aux.second << "\n";
    }    
    return 0;
}