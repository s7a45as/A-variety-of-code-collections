#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define pii pair<int,int>
const int N=1e5+15;

pii tp[N];
	int n,k;
int check(int x){
	int sum=0;
	for(int i=1;i<=n;i++){
		int c=tp[i].first;
		int d=tp[i].second;
		sum+=(c/x)*(d/x);
		
	}	if(sum>=k) return true;
		else  return false;
		
	
}

void solve(){

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>tp[i].first>>tp[i].second;
		
	}
	int l=1;
	int r=1e5;
	int ans=0;
	
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			// cout<<mid<<endl;
				ans=mid;
			l=mid+1;
		
			
		}else{
			r=mid-1;
			
		}
	}
	cout<<ans<<endl;
	
		
}
signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	
}
