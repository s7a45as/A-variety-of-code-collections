#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=1e5;



void solve(){
    int n;
    string x;
    int m,k;
    cin>>n>>x>>m>>k;
    if(k==n){
    	cout<<"mei you mai "<<x<<" de";
    	
    	
	}else if(k==m){
			cout<<"kan dao le mai "<<x<<" de";
	}else{
		cout<<"wang le zhao mai "<<x<<" de";
	}
}

signed main() {
    int t = 1;
    while (t--) solve();
    return 0;
}
