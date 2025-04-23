#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
map<int,double>mp;
double tb[1213];

void solve(){
	 int t;
	 cin>>t;
	 if(t==0){
	 	printf("%.2lf\n",t);
	 	return ;
	 	
	 }
	for(int i=1;i<=t;i++){
		double a;
		cin>>a;
		mp[i]=a;
		
	}
	int a,b;
	double sum=0.0;
	
	while(cin>>a>>b){
		if(a==0||b==0)break;
		sum+=mp[a]*b;
		tb[a]+=b;
//		cout<<a<<" 2"<<endl;
		
	}
	for(int i=1;i<=t;i++){
		cout<<tb[i]<<endl;
		
	
	}printf("%.2lf\n",sum);
	
	 
}
signed main(){
	solve();
	
}
