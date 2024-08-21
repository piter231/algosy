#include <bits/stdc++.h>
#include "bthlib.h"

using namespace std;

namespace libVariables{
    set<string> set_;
    bool compiled;
    vector<int> p;
    int n,m,k;
}

using namespace libVariables;

void init(int & N, int & K, int & M){
    cin>>n>>k>>m;
    N = n;
    M = m;
    K = k;
    p.resize(n);
    for (int i = 0; i < n; i++) cin>>p[i];
}
void dodaj(string s){
    if (k <= 0){
        cout<<"Zła odpowiedź\n";
        cout<<"Wykorzystano limit wywołań funkcji dodaj\n";
        exit(0);
    }   
    k--;
    if (compiled){
        cout<<"Zła odpowiedź\n";
        cout<<"Niepoprawna interakcja\n";
        exit(0);
    }
    set_.insert(s);
}
void let_him_cook(){
    if (compiled){
        cout<<"Zła odpowiedź\n";
        cout<<"Niepoprawna interakcja\n";
        exit(0);
    }
    compiled = 1;
    set<string> compiledSet;
    for (string s : set_){
        string s2 = s;
        for (int i = 0; i < n; i++) s2[i] = s[p[i]];
        compiledSet.insert(s2);
    }
    set_ = compiledSet;
}
bool zapytaj(string s){
    if (m <= 0){
        cout<<"Zła odpowiedź\n";
        cout<<"Wykorzystano limit wywołań funkcji zapytaj\n";
        exit(0);
    }   
    m--;
    if (!compiled){
        cout<<"Zła odpowiedź\n";
        cout<<"Niepoprawna interakcja\n";
        exit(0);
    }
    return (set_.find(s) != set_.end());
}
void odpowiedz(vector<int> ans){
    if (ans != p){
        cout<<"Zła odpowiedź\n";
        cout<<"Błędna permutacja\n";
    }else{
        cout<<"OK\n";
    }
    exit(0);
}
