#include<iostream>
#include<vector>
using namespace std;

constexpr int maxn=5e5+7, log=20;
//{v,c}
vector<pair<int, int>> mac[maxn];
long long odl[maxn];
int jmp[maxn][log];
int preorder[maxn], postorder[maxn], depth[maxn];
int tajm=0;

void dfs(int v, int p){
    preorder[v]=tajm++;
    for(auto [w,c] : mac[v]){
        if(w!=p){
            depth[w]=depth[v]+1;
            jmp[w][0]=v;
            for(int j=1;j<log;++j)jmp[w][j]=jmp[jmp[w][j-1]][j-1];
            odl[w]=odl[v]+c;
            dfs(w,v);
        }
    }
    postorder[v]=tajm++;
}
bool is_subtree(int a, int b){
    if(preorder[a]<preorder[b] && postorder[b]<postorder[a]){
        return true;
    }
    return false;
}
int lca(int a, int b){
    if(depth[b]>depth[a]) swap(a,b);
    if(is_subtree(b,a) || a==b) return b;
    //b jest wyzej, a jest glebiej
    for(int i=log-1;i>=0;--i){
        if(jmp[a][i] && !is_subtree(jmp[a][i],b))a=jmp[a][i];
    }

    a=jmp[a][0];
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i,j,a,b,c;
    cin>>n;
    for(i=1;i<n;++i){
        cin>>a>>b>>c;
        mac[a].push_back({b,c});
        mac[b].push_back({a,c});
    }
    dfs(1,1);
    /*
    for(i=1;i<=n;++i){
        for(j=0;j<3;++j){
            cout<<jmp[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    //cout<<lca(5,4);
    for(cin>>a;a!=-1;cin>>a){
        cin>>b;
        cout<<odl[a]+odl[b]- (odl[lca(a,b)]<<1)<<'\n';
    }
}