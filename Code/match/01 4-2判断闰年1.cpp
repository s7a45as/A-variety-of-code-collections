#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
void solve(){
	int n;
	cin>>n;
	if(n%4==0||n%400==0){
		printf("%lld is leap year.",n);
		
	}else{
		printf("%lld is not leap year.",n);
	}
}

signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	
}
