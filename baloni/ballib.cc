#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> balony;
vector<int> podanyBalon;



int liczba_malpek()
{
	return balony.size();	
}

int kolejny_balon(int i)
{
	cout<<"pod"<<podanyBalon[i]<<'\n';
	if(podanyBalon[i] < balony[i].size()){
		cout<<podanyBalon[i]<<'\n';
		podanyBalon[i]+=1;
		cout<<podanyBalon[i]<<'\n';
		return balony[i][podanyBalon[i]];
	}
	return -1;
}
int minimalna_liczba_rzutow(){
    int nn=liczba_malpek(); 
    int output=0;
    int wczytany;
	cout<<'x'<<nn<<'\n';
    for(int i=1;i<nn;++i){
		cout<<"sfdddfsfds"<<i<<'\n';
        unordered_map<int, int> zlicz;
        for(wczytany=kolejny_balon(i); wczytany!=-1;){
			cout<<"wczytany"<<wczytany<<' '<<podanyBalon[i]<<'\n';
            if(zlicz[wczytany]>0){
                --zlicz[wczytany];
            }
            ++zlicz[wczytany-1];
        }
        for(auto xd : zlicz)output+=xd.second;
    }
    return output;
}


int main()
{
	cin >> n;
	cout<<n<<'\n';
	balony.push_back({});
	podanyBalon.push_back(0);
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x;
		balony.push_back({});
		podanyBalon.push_back(0);
		for(int j = 0; j < x; j++)
		{
			cin >> y;
			balony[i].push_back(y);
		}
		cout<<"skobczylem\n";
	}

	cout << minimalna_liczba_rzutow() << '\n';
}
