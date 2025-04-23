#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=1005;
map<string,int>mp;
map<string ,double>mp2;

void solve(){
 int n;
 cin>>n;
 for(int i=0;i<n;i++){
 	string s;
 	cin>>s;
 	mp[s]=1;
 	
 }
 int t;
 cin>>t;double sum=0;
 double tn=t;
 
 while(t--){
 	string a;
 	int b;
 	cin>>a>>b;
 	sum+=b;
 	mp2[a]=b;
 	
 }
 sum/=tn;
 int f=0;
 
 for(auto p:mp2){
 	string name=p.first;
 	int b=p.second;
 	if(!mp[name]&&b>sum){
 		cout<<name<<endl;
 		f=1;
 		
	 }
 }
 
 if(!f)cout<<"Bing Mei You"<<endl;
 
	

}

signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	
}
