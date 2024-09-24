#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int a, i;
    cin >> i;
    while(i--){
        cin >> a;
        if(a%2){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            int aux=a/2;
            while(aux--) cout<<"AAB";
            cout<<endl;
        }
    }
    return 0;
}