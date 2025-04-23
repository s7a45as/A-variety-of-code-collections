#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
set<int>s;

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		auto it =s.lower_bound(a);
		
		if(it!=s.end()){
			s.erase(it);
			s.insert(a);
//			cout<<"a---21   "<<a<<endl;
			
		}else 
		{
		s.insert(a);	
//		cout<<"a---11   "<<a<<endl;
		}
		
	}
	cout<<s.size()<<endl;
	
}
signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
}

