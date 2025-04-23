#include<bits/stdc++.h>
using namespace std;
 struct Edge{
 	ll v,w,next;
 	
 }G[N];
 
 ll head[N],cnt,n,m,s;
 ll dis[N];
 
 void addedge(ll u,ll v,ll w){
 	cnt++;
 	G[cnt].v=v;
 	G[cnt].w=w;
 	G[cnt].next=head[u];
 	head[u]=cnt;
 	
 }
 struct node{
 	ll d,u;
 	bool operator<(const node&t)const{
	 	return d>t.d;
	 	//优先队列是相反的 
	 }
 };
 void Dijkstra(){
 	for(int i=1;i<=n;i++)dis[i]=mod;
 	dis[s]=0;
 	priority_queue<node>q;
 	q.push((node){0,s
	 });
	 while(!q.empty())
	 {
	 	node tmp=q.top();q.pop();
	 	ll u=tmp.u;ll d =tmp.d;
	 	if(d!=dis[u])continuel
	 	for(int i=head[u];i;i=G[i].next){
	 		ll v=G[i].v;
	 		ll w=G[i].w;
	 		if(dis[u]+w<dis[v]){
	 			dis[v]=dis[u]+w;
	 			q.push((node){dis[v],v
				 })
			 }
		 }
	 }
 }
