#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct Node {
    vector<int> seq;
    int cnt;
    
    bool operator<(const Node& t) const {
        return cnt != t.cnt ? cnt > t.cnt : seq < t.seq;
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    
    map<vector<int>, int> mp;
    for(int i=0; i<n; i++) {
        vector<int> tmp(m);
        for(int j=0; j<m; j++) 
            cin >> tmp[j];
        mp[tmp]++;
    }
    
    vector<Node> ans;
    for(auto& [seq,cnt] : mp) 
        ans.push_back({seq, cnt});
    
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << endl;
    for(auto& [seq,cnt] : ans) {
        cout << cnt;
        for(int num : seq) 
            cout << " " << num;
        cout << endl;
    }
}
