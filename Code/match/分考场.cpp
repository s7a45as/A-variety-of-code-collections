#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

const int N=121;
int a[N][N];
vector<int>kao[N];
int n,m;
int ans=INT_MAX;


void dfs(int x,int room){
	if(room>N){
		return ;
		
	}
	if(x>n){
		ans=min(ans,room);
		return;
		
	}
	for(int i=1;i<=room;i++){
		bool c=0;
		
		for(int j=0;j<kao[i].size();j++){
			if(a[x][kao[i][j]]){
				c=1;
				
				break;
			}
			
		}
		if(!c){
			kao[i].push_back(x);
			dfs(x+1,room);
			kao[i].pop_back();
			
		}
	}
	kao[room+1].push_back(x);
	dfs(x+1,room+1);
	kao[room+1].pop_back();
	
	
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int c,d;
		cin>>c>>d;
		a[c][d]=1;
		a[d][c]=1;
		
		
	}
	dfs(1,0);
	cout<<ans<<endl;
	
	
}
