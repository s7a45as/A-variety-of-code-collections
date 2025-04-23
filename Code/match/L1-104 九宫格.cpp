#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=4*1e5+5155;
set<int>s;

void solve(){
	s.clear();
	int G[10][10];
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cin>>G[i][j];
			
		}
	}
	int gong=0;
	int hang=0;
	int lie=0;
	for(int t=0;t<3;t++)
	{
	
	for(int x=0;x<3;x++){
		for(int i=1+x*3;i<=3+x*3;i++){
		
			for(int j=1+t*3;j<=3+t*3;j++){
			
				s.insert(G[i][j]); 
				if(G[i][j]>9||G[i][j]<1)
				{
					cout<<0<<endl;
					return ;
				}
				
//				cout<<G[i][j];
			}
			
		}
//		cout<<endl;
		
		
		if(s.size()!=9){
			cout<<0<<endl;
//			cout<<"gong"<<s.size()<<endl;
			return ;
			
		}
		s.clear();
	}
	
//	cout<<endl;
	
}
	s.clear();
	
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			s.insert(G[i][j]);
			
		}
		if(s.size()!=9){
			cout<<0<<endl;
//				cout<<"hang"<<endl;
			return ;
			
		}
		s.clear();
	}
	s.clear();
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			s.insert(G[j][i]);
			
		}
		if(s.size()!=9){
			cout<<0<<endl;
//				cout<<"lie"<<endl;
			return ;
			
		}
		s.clear();
	}
	cout<<1<<endl;
	
	
} 

signed  main(){
	
	int t=1;
	cin>>t;
	while(t--)
	solve();
}
