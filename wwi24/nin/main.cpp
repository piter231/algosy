#include<iostream>
#include<numeric>

constexpr int mod=1e9+7;

long long pow(long long a, long long b){
    if(b==0) return 1;
    else if(b%2==1){
        return (pow((a*a)%mod, b/2)*a)%mod;
    }
    else return (pow((a*a)%mod, b/2))%mod;
}
long long silnia(int n){
    long long output=1;
    for(int i=1;i<=n;++i){
        output=(output*i)%mod;
    }
    return output;
}

long long dwumian(long long n, long long k){
    long long output=silnia(n);
    output=(output*pow((silnia(k)*silnia(n-k))%mod, mod-2))%mod;
    return output;
}

long long xGCD(long long a, long long b, long long &x, long long &y) {
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    long long x1, y1;
    long long gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;

}

void solve(){
    int a,b,c;
    std::cin>>a>>b>>c;
    long long x,y;
    long long nwd=xGCD(b,c,x,y);
    //std::cout<<nwd<<' '<<x<<' '<<y<<'\n';
    if(a%nwd!=0){
        std::cout<<"NIE";
        return;
    }
    int mno=a/nwd;
    x*=mno;
    y*=mno;
    //std::cout<<nwd<<' '<<x<<' '<<y<<'\n';

}

int main(){
    int n;
    std::cin>>n;
    while(n--){
        solve();
    }
}