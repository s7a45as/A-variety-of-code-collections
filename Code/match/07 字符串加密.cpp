#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=1e5;



void solve(){
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if((s[i]<='z'&&s[i]>='a')|(s[i]<='Z'&&s[i]>='A'))
		{
			if(s[i]=='z'){
			s[i]='a';
			
		}else if(s[i]=='Z'){
			s[i]='A';
			
		}else{
			int a=s[i];
			a++;
			s[i]=char(a);
			
		}
		}
		
	}
	cout<<s<<endl;
	
  
}

signed main() {
    int t = 1;
    while (t--) solve();
    return 0;
}
