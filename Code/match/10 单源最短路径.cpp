#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
const int N = 1e6 + 10;  

struct Edge {
    int v, w, next;
} e[N];
int head[N];
int cnt = 0;
int dist[N];
bool vis[N];
int n, s, d;

void add(int u, int v, int w) {
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[s] = 0;
   
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    
    while (!pq.empty()) {
    	auto tmp=pq.top();
        pq.pop();
        int d_u=tmp.first;
        int u=tmp.second;
        if (vis[u]) continue;
        vis[u] = true;
        
        if (u == d) break;
        
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            int w = e[i].w;
            if (dist[v] > d_u + w) {
                dist[v] = d_u + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve() {
    cin >> n >> s >> d;
    if (s == d) {
        cout << 0 << endl;
        return;
    }
    memset(head, -1, sizeof(head));
    cnt = 0;
    
    for (int i = 0; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    
    dijkstra();
    
    if (dist[d] != 0x3f3f3f3f3f3f3f3f) {
        cout << dist[d] << endl;
    } else {
        cout << -1 << endl;
    }
}

signed main() {
  
    int t = 1;
    while (t--) solve();
    return 0;
}
