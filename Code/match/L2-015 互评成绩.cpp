#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
vector<double>q;

void solve(){
	int n,k,m;
	cin>>n>>k>>m;
	while(n--){
		double minx=1e6;
		double maxx=0;
		double sum=0;
		for(int i=1;i<=k;i++){
	
		
		double a;
		cin>>a;
		sum+=a;
		minx=min(minx,a);
		maxx=max(maxx,a);
		}
		sum-=minx;
		sum-=maxx;
		double t=k-2;
		double ans=sum/t;
		q.push_back(ans);
		
		
		
			}
		sort(q.begin(),q.end(),greater<double>());
		for(int i=m-1;i>=0;i--){
			if(i!=0)
			printf("%.3lf ",q[i]);
			else printf("%.3lf",q[i]);
			
		}
}
signed main(){
	solve();
	
}
