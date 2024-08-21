#include <iostream>
#include <vector>
#include "jas.h"

using namespace std;

constexpr int maxn=5007;

int counted[maxn], inv[maxn];
bool tab[maxn];

vector<int> kolejnosc;

int main(){
    int n = init(), i,j;
    for(i=0;i<n;++i){
        counted[i]=-1;
        inv[i]=1;
    }
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            tab[j]=((inv[j]==-1) ? 0 : counted[inv[j]]);
        }
        cout<<"tab: ";
        for(j=0;j<n;++j){
            cout<<tab[j]<<' ';
        }
        cout<<'\n';
        int w1=wyprobuj(tab);
        for(j=0;j<n;++j){
            tab[j]=((inv[j]==-1) ? 1 : counted[inv[j]]);
        }
        cout<<"tab: ";
        for(j=0;j<n;++j){
            cout<<tab[j]<<' ';
        }
        cout<<'\n';
        int w2=wyprobuj(tab);
        cout<<w1<<' '<<w2<<'\n';
        for(j=0;j<n;++j){
            tab[j]=((inv[j]==-1) ? 0 : counted[inv[j]]);
        }
        if(w1==-1 || inv[w1]!=-1){
            kolejnosc.push_back(w2);
            inv[w2]=i;
            counted[i]=0;
            continue;
        }
        else if(w2 == -1 || inv[w2]!=-1){
            kolejnosc.push_back(w1);
            inv[w1]=i;
            counted[i]=1;
            continue;
        }
        int w3=wyprobuj(tab);
        tab[w1]=1;
        int w4=wyprobuj(tab);
        tab[w1]=0;
        tab[w2]=1;
        int w5=wyprobuj(tab);
        tab[w1]=1;
        int w6=wyprobuj(tab);
        cout<<w3<<' '<<w4<<' '<<w5<<' ' <<w6<<'\n';
        int gorny=-1;
        if(w3 == w4 || w3 == w5 || w3 == w6) gorny=w3;
        else if(w4 == w5 || w4 == w6) gorny=w4;
        else gorny=w5;
        if(gorny == w1){
            kolejnosc.push_back(w1);
            counted[w1]=1;
        }
        else{
            kolejnosc.push_back(w2);
            counted[w2]=0;
        }
    }
    for(auto xd : kolejnosc)cout<<xd<<' ';
    cout<<'\n';
    for(i=0;i<n;++i){
        cout<<counted[i]<<' ';
    }
    cout<<'\n';
}
