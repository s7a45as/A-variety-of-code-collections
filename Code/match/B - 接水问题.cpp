#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int s[11000],ans;  
void solve() {
  
	
	
	int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];   
	int t=m+1;   
	while(t<=n+m)
	{
		for(int i=1;i<=m;i++)     
		{
			s[i]--;
			if(s[i]==0)
			{
				s[i]=s[t];    
				t++; 
			}
		}
		ans++;     
	}
		cout<<ans;

	 
 
}

signed main() {
    int t = 1;
    while (t--) solve();
}
