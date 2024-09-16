#include<iostream>
#include<vector>
using namespace std;

constexpr int maxn=2e5+7;
int input[maxn], booked[maxn];

int main(){
    int n,m,k,i,j=0;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i){
        cin>>input[i];
    }
    vector<int> indeksy;
    long long suma=0;
    for(i=1;i<=m;++i){
        booked[i]=max(0ll, min(k-suma, (long long)input[i]));
        suma+=booked[i];
        if(booked[i]<input[i]) indeksy.push_back(i);
        //cout<<booked[i]<<' ';
    }
    //cout<<'\n'<<suma;
    for(;i<=n;++i){
        j=i-m;
        suma-=booked[j];
        //suma aktualna
        indeksy.push_back(i);
        while(suma<k && !indeksy.empty() && indeksy.back()>j){
            int z_wierzchu=indeksy.back();
            int left_space=input[z_wierzchu] - booked[z_wierzchu];
            int booked_curr=max(0ll, min(k-suma, (long long)left_space));
            booked[z_wierzchu]+=booked_curr;
            if(input[z_wierzchu] == booked[z_wierzchu]) indeksy.pop_back();
            suma+=booked_curr;
        }
    }

    for(++j;j<=n;++j){
        suma-=booked[j];
        //cout<<indeksy.back()<<' '<<j<<' '<<suma<<'\n';
        while(suma<k && !indeksy.empty() && indeksy.back()>j){
            int z_wierzchu=indeksy.back();
            int left_space=input[z_wierzchu] - booked[z_wierzchu];
            int booked_curr=max(0ll, min(k-suma, (long long)left_space));
            //cout<<"booked_curr"<<' '<<booked_curr<<' '<<"left_space "<<left_space<<" suma "<<suma<<'\n';
            booked[z_wierzchu]+=booked_curr;
            if(input[z_wierzchu] == booked[z_wierzchu]) indeksy.pop_back();
            suma+=booked_curr;
        }
    }

    long long output=0;

    for(i=1;i<=n;++i){
       //cout<<booked[i]<<' ';
        output+=booked[i];
    }
    //cout<<'\n';
    cout<<output;
}