#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		if(a<=5&&a>=3){
			cout<<"Spring"<<endl;
			
		}else if(a<=8&&a>=6)
		{
			cout<<"Summer"<<endl;
		}else if(a<=11&&a>=9)
		{
			cout<<"Autumn"<<endl;
		}else if(a==12||a==1||a==2)
		{
			cout<<"Winter"<<endl;
		}
	}
	
}
signed main(){
	int t=1;
	while(t--)solve();
	
}

