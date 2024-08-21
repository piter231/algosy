#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

constexpr int maxn=5e5+7;
vector<int> mac[maxn];
int kol[maxn], kol_inv[maxn];
int ind=0;
bool odw[maxn];
int ojc[maxn];

vector<int> kol_nasza;

void dfs(int v){
    odw[v]=1;
    kol_nasza.push_back(v);
    sort(mac[v].begin(), mac[v].end(), [](int a, int b){
        return kol_inv[a]<kol_inv[b];
    });
    for(auto w : mac[v]){
        if(!odw[w]){
            dfs(w);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i,a,b;
    cin>>n>>m;
    for(i=0;i<m;++i){
        cin>>a>>b;
        mac[a].push_back(b);
        mac[b].push_back(a);
    }
    for(i=1;i<=n;++i){
        cin>>kol[i];
        kol_inv[kol[i]]=i;
    }
    dfs(kol[1]);
    //for(auto xd : kol_nasza){cout<<xd<<' ';}
    for(i=0;i<n;++i){
        if(kol_nasza[i]!=kol[i+1]) {
            cout<<"NIE";
            return 0;
        }
    }
    cout<<"TAK";
}