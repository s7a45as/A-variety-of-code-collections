#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define pii pair<int,int>
const int N=1e5+15;
queue<char>A,B;
stack<char>c;
map<char,int>vis; 

void solve(){
	
	string a,b;
	cin>>a>>b;
	for(int i=0;i<a.size();i++){
		A.push(a[i]);
		
	}
		for(int i=0;i<b.size();i++){
		B.push(b[i]);
		
	}
		while(!A.empty()||!B.empty()){
			
			char A_tmp=A.front();
			A.pop();
			if(vis[A_tmp]){
				while(vis[A_tmp]){
					char tmp=c.top();
					c.pop();
					A.push(tmp);
					if(tmp==A_tmp){
						vis[A_tmp]=0;
						
						break;
					}
					
				}
			}else{
				c.push(A_tmp);
				vis[A_tmp]=1;
			}
			
			
				char B_tmp=B.front();
			B.pop();
			if(vis[B_tmp]){
				while(vis[B_tmp]){
					char tmp=c.top();
					c.pop();
					B.push(tmp);
					if(tmp==B_tmp){
						vis[B_tmp]=0;
						
						break;
					}
					
				}
			}else{
				c.push(B_tmp);
				vis[B_tmp]=1;
				
			}
			
			
			
		}
	while(!A.empty()){
		char c=A.front();
		A.pop();
		cout<<c;
		
		
	}
		while(!B.empty()){
		char c=B.front();
		B.pop();
		cout<<c;
	}
	cout<<endl;
	
}
signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	
}
