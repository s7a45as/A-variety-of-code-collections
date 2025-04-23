#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=1e5;


void solve(){
    int n;
    cin >> n; 
    
    for (int i = -n; i <= n; ++i) {
        int s = abs(i);        
        int st = 2 * (n - s) + 1; 
        
        cout << string(s, ' ') << string(st, '*') << endl;
    }


	
}
signed main(){
	int t=1;
	while(t--)solve();
	
}

