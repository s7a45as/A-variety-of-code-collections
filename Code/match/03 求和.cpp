#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=1e5;

void solve(){
	int n;
	cin>>n;
	int ans=0;
	
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a<=10&&a>=-10){
			ans+=a;
			
		}
	}
	cout<<ans<<endl;
	
	
	
	
}
signed main(){
	int t=1;
	while(t--)solve();
	
}

