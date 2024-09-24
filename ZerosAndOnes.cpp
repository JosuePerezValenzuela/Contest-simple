#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
    string c;
    int contador = 0;
    while(cin >> c){
    int n;
    cin >> n;
    contador++;
    cout << "Case " << contador << ":" << endl;
    for(int i = 0; i < n; i++){
        string impresion = "Yes";
        int num1, num2;
        cin >> num1 >> num2;
        int a = min(num1, num2);
        int b = max(num1, num2);
        for(int j = a; j < b; j++){
            if((c[j] == c[j+1]) == false){
                impresion = "No";
                break;
            }
        }
        cout << impresion << endl;
    }
    }
    return 0;
}