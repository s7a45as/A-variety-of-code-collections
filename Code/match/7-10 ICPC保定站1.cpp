#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=500;
int a[N];
int n,t;
int ans;

void dfs(int sum){
    if(sum>t)return;
    if(sum<=t){
        ans=max(ans,sum);
        
    }
    for(int i=1;i<=n;i++){
        sum+=a[i];
        dfs(sum);
        sum-=a[i];
        
    }
}

void solve(){

    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        
    }
    dfs(0);
    cout<<ans<<endl;
    
    
}
signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	
}
