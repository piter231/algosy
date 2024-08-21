#include<bits/stdc++.h>

using namespace std;

constexpr int maxn=5e5+7;
constexpr long long inf=1e17;
vector<pair<int, int>> mac[2*maxn];
priority_queue<pair<long long, int>> q;
bool odw[maxn*2];

long long odl[2*maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i,a,b,c;
    cin>>n>>m;
    for(i=0; i<2*maxn;++i){
        odl[i]=inf;
    }
    for(i=0;i<m;++i){
        cin>>a>>b>>c;
        if(c%2==0){
            mac[a].push_back({b, c});
            mac[b].push_back({a, c});
            mac[a+maxn].push_back({b+maxn, c});
            mac[b+maxn].push_back({a+maxn, c});
        }
        else{
            mac[a].push_back({b+maxn, c});
            mac[b].push_back({a+maxn, c});
            mac[a+maxn].push_back({b, c});
            mac[b+maxn].push_back({a, c});
        }
    }
    odl[1]=0;
    //for(i=1;i<=n;++i)cout<<odl[i]<<' ';
    //cout<<'\n';
    q.push({0, 1});
    while(!q.empty()){
        int v=q.top().second;
        q.pop();
        if(odw[v]){continue;}
        odw[v]=1;
        for(auto [w, d] : mac[v]){
            if(odl[w]>odl[v]+d){
                odl[w]=odl[v]+d;
                if(!odw[w]){q.push({-odl[w], w});}
            }
        }
    }
    //for(i=1;i<=n;++i)cout<<odl[i]<<' ';
    long long maks=-1;
    for(i=1;i<=n;++i){
        long long out1=odl[i]+odl[maxn+i];
        if(out1<inf)maks=max(maks, out1);
    }
    if(maks==-1){
        cout<<"BRAK";
        return 0;
    } 
    for(i=1;i<=n;++i){
        long long out1=odl[i]+odl[maxn+i];
        if(out1==maks)cout<<i<<' ' ;
    }
    cout<<'\n'<<maks;
}