#include "ballib.h"
#include<bits/stdc++.h>

using namespace std;

struct amogus{
    size_t operator()(const int &x) const{
        return x^2137692137692137ll;
    }
};

int minimalna_liczba_rzutow(){
    int n=liczba_malpek(); 
    int output=0;
    int wczytany;
    for(int i=1;i<=n;++i){
        unordered_map<int, int, amogus> zlicz;
        for(wczytany=kolejny_balon(i); wczytany!=-1;wczytany=kolejny_balon(i)){
            if(zlicz[wczytany]>0){
                --zlicz[wczytany];
            }
            ++zlicz[wczytany-1];
        }
        for(auto xd : zlicz)output+=xd.second;
    }
    return output;
}
