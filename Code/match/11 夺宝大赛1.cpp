#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=1233;
int g[N][N];
int dist[N][N];
int vis[N][N];
vector<int>ans[N*N];
int x,y;
int e_x,e_y;
	int m,n;
struct node{
	int dist;
	int x;
	int y;
	bool operator<(const node&a)const{
		return dist>a.dist;
		 
	}
};
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void dijk(){
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	priority_queue<node>q;
	dist[e_x][e_y]=0;
	vis[e_x][e_y]=0;
	q.push({0,e_x,e_y});
	while(!q.empty()){
		node p=q.top();
		q.pop();
		if(vis[p.x][p.y])continue;
		vis[p.x][p.y]=1;
		for(int i=0;i<4;i++){
			int xx=p.x+dx[i];
			int yy=p.y+dy[i];
			if(xx<1||xx>m||yy<1||yy>n) continue;
			if(g[xx][yy]==0)continue;
			if(dist[xx][yy]>dist[p.x][p.y]+1){
				dist[xx][yy]=dist[p.x][p.y]+1;
				q.push({dist[xx][yy],xx,yy});
				
			}
			
		}
	}
	
	
}


void solve(){

	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
			if(g[i][j]==2){
				e_x=i;
				e_y=j;
				
			}
			
		}
	}
	dijk();
	int k;
	cin>>k;

	
	for(int i=1;i<=k;i++){
		
	  cin>>y>>x;
	  	cout<<"dist  "<<dist[x][y]<<endl;
        if(dist[x][y]!=0x3f3f3f3f3f3f3f3f){
            ans[dist[x][y]].push_back(i);
        }
	} 
	bool f=1;
	int id=0;
	int disst=0;
	
	for(int i=1;i<=n*m;i++){
		if(ans[i].size()!=1)continue;
		f=0;
		id=ans[i][0];
		disst=i;
		
		
	}
	if(f){
		cout<<"No winner."<<endl;
		
	}else{
		cout<<id<<" "<<disst<<endl;
		
	}
	
	
	
} 
signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	
}
