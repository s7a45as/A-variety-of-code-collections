#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
int n,k;

struct node{
	vector<int>seq;
	int num;
	bool operator<(const node&a)const{
		if(num!=a.num){
			return num>a.num;
			
		}else return seq<a.seq;
		
	}
};
map<vector<int>,int>mp;
vector<node>ans;
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		vector<int>tmp(k);
		
		for(int j=0;j<k;j++){
			cin>>tmp[j];
			
		}
		mp[tmp]++;
		
	}
	for(auto& [seq,num]:mp){
		ans.push_back({seq,num});
		
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	 for(auto& [seq,cnt] : ans) {
        cout << cnt;
        for(int num : seq) 
            cout << " " << num;
        cout << endl;
    }
}
