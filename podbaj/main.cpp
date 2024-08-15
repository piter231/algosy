#include<iostream>
#include<map>

using namespace std;

constexpr int maxn=1e6+7, mod=1e9+696969;

map<pair<int, int>, int> mapa;

pair<int, int> pot[maxn], hsh[maxn];
pair<int, int> p={97, 17};

pair<int, int> get_hsh(int l, int r){
    pair<int, int> output;
    output.first=hsh[r].first-hsh[l].first;
    output.first=((long long)output.first+mod)%mod;
    output.second=hsh[r].second-hsh[l].second;
    output.second=((long long)output.second+mod)%mod;
    output.first=((long long)(output.first)*pot[maxn-r-1].first)%mod;
    output.second=((long long)(output.second)*pot[maxn-r-1].second)%mod;
    return output;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i,j;
    cin>>n;
    pot[0]={1,1};
    for(i=1;i<maxn;++i){
        pot[i].first=((long long)pot[i-1].first*p.first)%mod;
        pot[i].second=((long long)pot[i-1].second*p.second)%mod;
    }
    string in;
    int output=0;
    for(i=0;i<n;++i){
        cin>>in;
        int m=(int)(in.length());
        for(j=0;j<m; ++j){
            hsh[j+1]={(hsh[j].first+in[j]*(long long)pot[j].first)%mod, 
            (hsh[j].second+in[j]*(long long)pot[j].second)%mod};
        }
        //auto curr_hash=get_hsh(0,m);
        //cout<<curr_hash.first<<' '<<curr_hash.second<<'\n';
        int max_wynik=0;
        pair<int, int> hsh_pocz, hsh_kon;
        for(j=1;j<=m;++j){
            hsh_pocz=get_hsh(0, j), hsh_kon=get_hsh(m-j, m);
            //cout<<hsh_pocz.first<<' '<<hsh_kon.first<<' '<<hsh_pocz.second<<' '<<hsh_kon.second<<'\n';
            if(hsh_pocz==hsh_kon){
                max_wynik=max(max_wynik, mapa[hsh_pocz]);
            }
        }
        mapa[hsh_pocz]=max_wynik+1;
        output=max(output, max_wynik+1);
        //cout<<mapa[hsh_pocz]<<'\n';
    }
    cout<<output;
}