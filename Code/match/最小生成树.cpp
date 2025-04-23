#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define pii pair<int,int>
const int N=1e6;
struct edge{
	int u,v,w;
	bool operator<(edge & a)const {
	return w<a.w;
	
	
	}
}e[N];
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
	
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		
	}
	sort(e+1,e+1+m);
	int ans=0;
	
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int tu=find(e[i].u);
		int tv=find(e[i].v);
		if(tu==tv)continue;
		fa[tu]=tv;
		ans+=e[i].w;
		
	} printf("%d\n",ans);
}
