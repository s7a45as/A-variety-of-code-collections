#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
unordered_set<string> has_friends;
void solve(){
 	int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        vector<string> ids(K);
        for (int j = 0; j < k; ++j) {
            cin >> ids[j];
        }
    
        if (k > 1) {
            for (auto id : ids) {
                has_friends.insert(id);
            }
        }
    }

    int m;
    cin >> m;
    vector<string> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i];
    }

    vector<string> result;
    unordered_set<string> added;


    for (auto id : queries) {
        if (has_friends.find(id) == has_friends.end() && added.find(id) == added.end()) {
            result.push_back(id);
            added.insert(id);
        }
    }


    if (result.empty()) {
        cout << "No one is handsome";
    } else {
        for (int i = 0; i < result.size(); ++i) {
            if (i != 0) cout << " ";
            cout << result[i];
        }
    }
    cout << endl;
	

}

signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	
}
