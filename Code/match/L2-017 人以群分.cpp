#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define pii pair<int,int>
const int N=1e6;
int a[N];

void solve(){
	int n;
	cin>>n;
	int sum=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		
	}
	sort(a+1,a+1+n);
	printf("Outgoing #: %lld\n",(n+1)/2);
	printf("Introverted #: %lld\n",(n-(n+1)/2));
	int sum1=0;
	
	for(int i=1;i<=((n+1)/2);i++){
		sum1+=a[i];
		
	}
	printf("Diff = %lld\n",sum-sum1);
	
} 
signed main(){
	void solve();
}
