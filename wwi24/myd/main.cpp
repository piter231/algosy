#include<iostream>

using  namespace std;

constexpr int maxn=1e5+7;
int input[maxn];
int pref[maxn];
int n;

bool check(int k){
	int i;
	for(i=1;i<=n;++i){
		pref[i]=((pref[i]<=k) ? -1 : 1);
	}
	
}

int main(){
	int i;
	for(i=1;i<=n;++i){
		cin>>input[i];
	}
	
}
