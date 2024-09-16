#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

constexpr int maxn=5e5+7;
vector<int> mac[maxn];
vector<int> rev_mac[maxn];
int scc_ind=0;
int scc_tab[maxn];
int rozm_scc[maxn];
vector<int> kol;
bool odw[maxn];
int doch[maxn];
int output[maxn];

void dfs(int v){
    odw[v]=1;
    for(auto w : mac[v]){
        if(!odw[w]){
            dfs(w);
        }
    }
    kol.push_back(v);
}

void scc(int v){
    odw[v]=1;
    scc_tab[v]=scc_ind;
    ++rozm_scc[scc_ind];
    for(auto w : rev_mac[v]){
        if(!odw[w]){
            scc(w);
        }
    }
}
void dfs2(int v){
    odw[v]=1;
    for(auto w : rev_mac[v]){
        if(!odw[w]){
            if(scc_tab[v]!=scc_tab[w]){
                output[w]=output[v]+rozm_scc[scc_tab[w]];
            }
            else output[w]=output[v];
        }
    }
}

int main(){
    int n,m,i,j, prev,t;

    cin>>n>>m;
    for(i=0;i<m;++i){
        cin>>prev;
        for(j=1;j<n;++j){
            cin>>t;
            mac[prev].push_back(t);
            rev_mac[t].push_back(prev);
            prev=t;
        }
    }
    for(i=1; i<=n; ++i){
        if(!odw[i]) dfs(i);
    }
    reverse(kol.begin(), kol.end());
    for(i=0;i<=n;++i) odw[i]=0;
    for(auto xd : kol)cout<<xd<<' ';
    cout<<'\n';
    for(j=0; j<n; ++j){
        i=kol[j];
        if(!odw[i]) {
            scc(i);
            ++scc_ind;
        }
    }
    for(i=1; i<=n;++i){
        cout<<scc_tab[i]<<' ';
    }
    cout<<'\n';

    for(i=0;i<=n;++i) odw[i]=0;
    int scc_pocz=kol[n-1];
    cout<<scc_pocz<<'\n';
    output[scc_pocz]=rozm_scc[scc_tab[scc_pocz]];
    dfs2(scc_pocz);
    for(i=1; i<=n; ++i){
        cout<<output[i]<<' ';
    }
}