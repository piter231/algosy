#include<iostream>
#include<cmath>
using namespace std;

constexpr int mod=1e9+7;

long long d(long long a, long long b){
    if((a>=0) == (b>=0)){
        return a/b;
    }
    else{
        if(a%b==0) return a/b;
        return a/b-1;
    }
}

long long nwd(long long a, long long b, long long &x, long long &y){
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    long long x1, y1;
    long long _nwd=nwd(b, a%b, x1, y1);
    x=y1;
    y=x1- (d(a, b))*y1;
    return _nwd;
    
}

long long silnia(int n){
    int i;
    long long output=1;
    for(i=1;i<=n;++i){
        output=(i*output)%mod;
    }
    return output;
}

long long pot(long long a, long long b){
    if(b==0) return 1;
    if(b%2==1) return (pot((a*a)%mod, b/2)*a)%mod;
    return pot((a*a)%mod, b/2)%mod;
}

long  long dwumian(long long n, long long k){
    return (silnia(n)*pot((silnia(k)*silnia(n-k))%mod , mod-2))%mod;
}

void solve(){
    long long a,b,c,x,y;
    cin>>a>>b>>c;
    long long _nwd=nwd(b,c,x,y);
    if(a%_nwd!=0){
        cout<<"NIE\n";
        return;
    }
    long long mno=a/_nwd;
    x*=mno;
    y*=mno;
    cout<<x<<' '<<y<<' '<<a<<'\n';
    if(x<0){
        x=-x, y=-y, a=-a;
    }
    //x jest dodatnie
    //cout<<do_dodania<<'\n';
    long long nowy1=x, nowy2=d(x,c)/_nwd;
    //cout<<i1<<' '<<i2<<' '<<nowy1<<' '<<nowy2<<'\n';
    if(abs(nowy1)>abs(nowy2)){
        x=nowy2, y-=b/_nwd;
    }

    cout<<x<<' '<<y<<'\n';
    cout<<dwumian( abs(x)+abs(y), abs(x))<<'\n';

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,p;
    cin>>t;
    while(t--)
         solve();
    //
}