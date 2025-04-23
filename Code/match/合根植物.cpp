#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=1e6+123;
map<int,int> mp;
int ans=0;

int n, m;
int fa[N];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

signed main() {
    cin >> m >> n;
    for(int i = 1; i <= m * n; ++i) {
        fa[i] = i;
    }
    int k;
    cin >> k;
    while(k--) {
        int a, b;
        cin >> a >> b;
        int ta = find(a);
        int tb = find(b);
        if(ta != tb) fa[ta] = tb;
    }
    for(int i = 1; i <= n*m; ++i) { 
        int root = find(i);
        if(!mp[root]) {
            ans++;
            mp[root] = 1;
        }
    }
    cout << ans << endl;
}
