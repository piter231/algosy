#include<iostream>
#include<algorithm>

using namespace std;

constexpr int maxn=1e5+7;
int input[maxn];
int pref[maxn], suf[maxn];
constexpr auto s="_hard_";
constexpr auto sr="_drah_";

int main(){
	int n,i;
	string in;
	cin>>n>>in;
	for(i=0;i<n;++i){
		cin>>input[i];
	}
	if(in[0]==s[1]) pref[0]=1;
	for(i=1;i<n;++i){
		if(pref[i-1]==4) pref[i]=pref[i-1];
		else{
			pref[i]=pref[i-1]+(s[pref[i-1]+1]==in[i]);
		}
	}
	for(i=0;i<n;++i)
		cout<<pref[i]<<' ';
	cout<<'\n';
	suf[n-1]=(in[n-1]==sr[4]);
	for(i=n-2;i>=0;--i){
		if(suf[i]==4) suf[i]=suf[i+1];
		else{
			suf[i]=suf[i+1]+(sr[suf[i+1]+1]==in[i]);
		}
	}
    for(i=0;i<n;++i)
        cout<<suf[i]<<' ';
	cout<<'\n';

}
