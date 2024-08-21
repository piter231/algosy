#include<bits/stdc++.h>
#include "bthlib.h"

using namespace std;

vector<int> gen_los(int n){
    int i;
    vector<int> output(n);
    for(i=0;i<n;++i){
        output[i]=i;
    }
    mt19937 seed;
    shuffle(output.begin(), output.end(), seed);
    return output;
}

int main(){
    int n,k,m,i,j;
    init(n,k,m);
    vector<int> done(n);
    for(i=0;i<n;++i) done[i]=-1;
    for(i=0;i<n;++i){
        string s;
        for(j=0;j<n;++j){
            s+= (j<=i) ? '1' : '0';
        }
        dodaj(s);
    }
    let_him_cook();
    for(int x=0;x<n;++x){    
        vector<int> kol = gen_los(n);;
        for(i=0;i<n;++i){
            if(done[kol[i]]!=-1) continue;
            string s;
            for(j=0;j<n;++j){
                if(done[j]!=-1){
                    s+='1';
                }
                else s+= (kol[i]==j) ? '1' : '0';
            }
            if(zapytaj(s)){
                done[kol[i]]=x;
                break;
            }
        }
    }

    odpowiedz(done);
}