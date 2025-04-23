#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=4*1e5+5155;
int dp[N];
int M,S,T;

void solve(){
	cin>>M>>S>>T;
	for(int i=1;i<=T;i++){
		if(M>=10){
			dp[i]=dp[i-1]+60;
			M-=10;
			
		}else{
			dp[i]=dp[i-1];
			M+=4;
		}
		
		
	}
	for(int i=1;i<=T;i++){
		dp[i]=max(dp[i],dp[i-1]+17);
		if(dp[i]>=S){
			cout<<"Yes"<<endl;
			cout<<i<<endl;
			return ;
			
		}
		
	}
	cout<<"No"<<endl;
	cout<<dp[T]<<endl;
	 
	
} 

signed  main(){
	
	int t=1;
//	cin>>t;
	while(t--)
	solve();
}
