#include <bits/stdc++.h>
#include "bthlib.h"

/*
Przykładowe (błędne) rozwiązanie do zadania bth
*/
using namespace std;

int main(){
    int n,m,k;
    init(n,m,k);
    dodaj("1000");
    dodaj("0011");
    let_him_cook();
    if (zapytaj("1000") == false){
        if (zapytaj("0100") == true && zapytaj("1010") == true){
            vector<int> p = {2,0,3,1};
            odpowiedz(p);
        }else{
            vector<int> p = {0,1,2,3};
            odpowiedz(p);
        }
    }
    return 0;
}