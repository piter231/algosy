#include<iostream>

using namespace std;

constexpr int base=1<<20;

int tree1[base*2], tree2[base*2];

void write(int v, int w, int* tree){
v+=base;
while(v>0){
    tree[v]=(tree[v]+w+11)%11;
    v/=2;
}
}

int read(int v, int lo, int ro, int lz, int rz, int* tree){
if(ro<lz || rz<lo) return 0;
else if(lz<=lo && ro<=rz) return tree[v];
return (read(v*2, lo, (lo+ro)/2, lz, rz,  tree) + 
    read(v*2+1, (lo+ro)/2+1, ro, lz, rz, tree)+11)%11;
}

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
int n, q, i;
cin>>n>>q;
string buff;
cin>>buff;
int liczba;

for(i=0;i<n;++i){
    liczba=buff[i]-'0';
    
    write(i,  ((i%2==0) ? liczba : -liczba), tree1);
    write(i,  ((i%2==1) ? liczba : -liczba), tree2);
}

//for(i=0;i<n;++i){
//    cout<<read(1, 0, base-1, i,i, tree1)<<' ';
//}
char op;
int a;

for(i=0;i<q;++i){
    cin>>op>>a>>liczba;
    if(op=='='){
        write(a, -read(1, 0, base-1, a, a, tree1) + ((a%2==0) ? liczba : -liczba), tree1);
        write(a, -read(1, 0, base-1, a, a, tree2) + ((a%2==1) ? liczba : -liczba),tree2);
    }
    else{
        int output=read(1, 0, base-1, a, liczba, tree1);
        if(liczba%2==1)output=(11-output)%11;
        output=((output+11)%11);
        cout<<output<<'\n';

    }
}
}
//((liczba%2==0) ?