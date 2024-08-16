#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=207, mod=1e9+7;
int input[maxn];
char operators[maxn];
int n;

long long silnia(int i){
    long long output=1;
    for(long long j=1;j<=i;++j){
        output=(j*output)%mod;
    }
    return output;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i;
    cin>>n;
    long long output=1;
    for(i=0;i<n;++i){
        cin>>input[i];
        output=(input[i]*output)%mod;
    }
    for(i=1;i<n;++i){
        cin>>operators[i];
    }
    //silnia();
    output*=silnia(n-1);
    output=output%mod;
    cout<<output;
}