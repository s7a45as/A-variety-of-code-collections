#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=1e6;
int n;
int index=0;
vector<int>ans[N];
vector<int>a;

void dfs(int l,int r,int index){
	
	if(l>r)return ;
	index++;
	
	int mid=(l+r)/2;
	ans[index].push_back(a[mid]);
	
	dfs(l,mid,index);
	dfs(mid+1,r,index);
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,n,0);
	for(int i=1;i<=3;i++){
		for(auto p:ans[i]){
			cout<<p<<" ";
		}cout<<endl;
		
		
	}
	
	
}
signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
}
