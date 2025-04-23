#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
int a[2]={1,2};
int ans=0;
	int n;
void dfs(int cur){
	if(cur>n)return ;
	
	if(cur==n){
		ans++;
		return ;
		
	}
	for(int i=0;i<2;i++){
		int rw=cur+a[i];
		dfs(rw);
		 
	}
}

void solve(){

	cin>>n;
	dfs(0);
	cout<<ans<<endl;
	
	

}

signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	
}
