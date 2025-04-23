#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=12130;
int g[N][N];
int vis[N];
int n,m;
void dfs(int city){
	vis[city]=1;
	for(int i=0;i<n;i++){
		if(!vis[i]&&g[i][city]){
			dfs(i);
			
		}
	}
}

int count(){
	int cnt=0;
	memset(vis,0,sizeof vis);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i);
			cnt++;
			
		}
	}
	return cnt;
	
}
void solve(){

	cin>>n>>m;
	while(m--) {
		int a,b;
		cin>>a>>b;
		g[a][b]=1;
		g[b][a]=1;
		
	}
	int k;
	cin>>k;
	int cnt=count();
//	cout<<"cnt  "<<cnt<<endl;
	int num=0;
	
	
	while(k--){
		num++;
		
		int a;
		cin>>a;
 		for(int j = 0; j < n; j++){
            if(g[a][j]){
                g[a][j] = 0, g[j][a] = 0;
            }
        }
		int tmp_cnt=count();
		
		if(1+cnt<tmp_cnt){
			printf("Red Alert: City %lld is lost!\n",a);
			
		}else 	printf("City %lld is lost.\n",a);
			
		cnt=tmp_cnt;
		if(num==n)	printf("Game Over.\n");
			
		
		
	}
}
signed main(){
	int t=1;
	while(t--)solve();
}

