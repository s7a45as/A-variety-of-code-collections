#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll inf=0x3f3f3f3f3f3f3f3f;
void solve(){
	int n;cin>>n;
	vector<int> a(n+1);
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	int l,r;
	l=r=-1;
	for(int i=1;i<=n;i++){
		if(mp[a[i]]==1){
			int tl=i;
			int tr=i;
			while(i+1<=n&&mp[a[i+1]]==1){
				i++;
				tr=i;
			}
			if(tr-tl>=r-l){
				l=tl;
				r=tr;
			}
		}
	}
	if(l==-1){
		cout<<0<<endl;return;
	}
	cout<<l<<" "<<r<<endl;
	return;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _;cin>>_;
	while(_--)solve();
}
