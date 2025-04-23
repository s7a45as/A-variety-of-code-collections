#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5000;
int fa[N];
int d[N][N];

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void solve() {
 int n,m,k;
 cin>>n>>m>>k;
 for(int i=1;i<=n;i++)fa[i]=i;
 while(m--){
 	int a,b,op;
 	cin>>a>>b>>op;
 	if(op==1){
 		int u=find(a);
 		int v=find(b);
 		if(u!=v){
 			fa[v]=u;
 			
		 }
	 }else {
	 	d[a][b]=1;
	 	d[b][a]=1;
	 	
	 }
 }
 while(k--){
 	int a,b;
 	cin>>a>>b;
 	if(find(a)==find(b)&&d[a][b]==0){
 		cout<<"No problem"<<endl;
 		
	 }else if(find(a)==find(b)&&d[a][b]==1){
	 	cout<<"OK but..."<<endl;
	 	
	 }else if(find(a)!=find(b)&&d[a][b]==0){
	 	cout<<"OK"<<endl;
	 	
	 }else if(find(a)!=find(b)&&d[a][b]==1){
	 	cout<<"No way"<<endl;
	 	
	 }
 }
}

signed main() {

    int testCases = 1;
    while (testCases--) solve();
}
