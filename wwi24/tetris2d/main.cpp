#include<iostream>

using namespace std;

constexpr int base=1<<20;
int tree[base*2], tree2[base*2];

void push(int v){
    if(tree2[v]==0) return;
    tree[2*v]=tree2[v];
    tree[v*2+1]=tree2[v];
    tree2[2*v]=tree2[v];
    tree2[2*v+1]=tree2[v];
    tree2[v]=0;
}

int read(int v, int lo, int ro, int lz, int rz){
    if(lz<=lo && ro<=rz) return tree[v];
    else if(ro<lz || rz<lo) return 0;
    push(v);
    return max(read(v*2, lo, (lo+ro)/2, lz, rz), read(v*2+1, (lo+ro)/2+1, ro, lz, rz));
}

void write(int v, int w, int lo, int ro, int lz, int rz){
    if(lz<=lo && ro<=rz) {
        tree[v]=w;
        tree2[v]=w;
    }
    else if(ro<lz || rz<lo) return;
    else{
        push(v);
        write(v*2, w, lo, (lo+ro)/2, lz, rz);
        write(v*2+1, w, (lo+ro)/2+1, ro, lz, rz);
        tree[v]=max(tree[v*2], tree[v*2+1]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int d,n,a,b;
    cin>>d>>n;
    for(int i=0; i<n;++i){
        cin>>a>>b;
        write(1, read(1, 0, base-1, b, b+a-1)+1, 0, base-1, b, b+a-1);
    }
    cout<<read(1,0, base-1, 0, base-1)<<'\n';
}