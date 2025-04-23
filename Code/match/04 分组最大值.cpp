#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=1e5;
vector<int>v;

void solve(){
	int n;
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n/2;i++){
			int a,b;
			cin>>a>>b;
		    v.push_back(min(a,b));
        
	}
    sort(v.begin(),v.end(),greater<int>());
    cout<<v[0]<<endl;
    

	
}
signed main(){
	int t=1;
	while(t--)solve();
	
}

