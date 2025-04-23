#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=1005;
int dp[N];
int v[N];
int w[N];

void solve(){
 	int n;
 	int V;
 	memset(dp,0,sizeof dp);
    cin >> n>>V;
    for(int i=1;i<=n;i++){
    	cin>>v[i]>>w[i];
    	
	}
	for(int i=1;i<=n;i++){
		for(int j=v[i];j<=V;j++)//ÍêÈ«±³°ü£¬ 
		{
			dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
			
		}
	}
	for(int i=1;i<=V;i++){
		cout<<dp[i]<<endl;
		
	}
	

}

signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	
}
