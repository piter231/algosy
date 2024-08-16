#include<iostream>

using namespace std;

constexpr int maxn=2e5+7, base=1<<18;
int in[maxn];
long long pref[maxn];
long long tree[base*2], tree2[base*2];

long long get_pref(int l, int r){
    return pref[r]-pref[l];
}
void syn(int v, int l, int r);
long long read(int v, int lo, int ro, int lz, int rz);

void syn(int v, int l, int r){
    if(tree2[v]==0) return;
    long long left=get_pref(l, (l+r)/2+1) - read(1, 0, base-1, l, (l+r)/2), right=get_pref((l+r)/2+1, r+1) - read(1,0, base-1, (l+r)/2+1, r);
    long long to_push=tree2[v];
    right=min(right, to_push);
    tree[v*2+1]+=right;
    tree2[v*2+1]+=right;
    to_push-=right;
    left=min(left, to_push);
    tree[v*2]+=left;
    tree2[v*2]+=left;
    tree2[v]=0;
}

long long read(int v, int lo, int ro, int lz, int rz){
    if(ro<lz || rz<lo) return 0;
    else if(lz<=lo && ro<=rz){
        return tree[v];
    }
    syn(v,lz, rz);
    return read(1, 0, base-1, lo, (lo+ro)/2) + read(1, 0, base-1, (lo+ro)/2+1, ro);
}

void write(int v, int w, int lo, int ro, int lz, int rz){
    if(ro<lz || rz<lo) return; 
    else if(lz<=lo && ro<=rz){
        tree[v]=w;
        tree2[v]=w;
        return;
    }
    syn(v, lz, rz);
    long long left=get_pref(lo, (lo+ro)/2+1) - read(1, 0, base-1, lo, (lo+ro)/2), right=get_pref((lo+ro)/2+1, ro+1) - read(1,0, base-1, (lo+ro)/2+1, ro);
    long long to_push=w;
    right=min(right, to_push);
    write(1, right, 0, base-1, lo, (lo+ro)/2);
    to_push-=right;
    left=min(left, to_push);
    write(1, left, 0, base-1, (lo+ro)/2+1, ro);
    tree[v]=(tree[v*2] + tree[v*2+1]);
}



int main(){
    int n,m,q,i;
    cin>>n>>m>>q;
    for(i=0;i<n;++i){
        cin>>in[i];
        pref[i+1]=in[i]+pref[i];
    }
    int j;
    for(i=0;i<n;++i){
        j=max(0, i-m);
        write(1, q, 0, base-1, j, i);
    }
    cout<<read(1, 0, base-1, 0, base-1);
}