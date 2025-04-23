#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10; 
typedef pair<int, int> pii;

vector<pii> cash_g[N];
vector<pii> lv_g[N]; 
int a[N];  
int dist1[N], dist2[N];
const int inf = 0x3f3f3f3f3f3f3f3f;

void djk(int start, int dist[], vector<pii> g[], int n) {
    fill(dist, dist + n + 1, inf);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, start});
    
    while (!q.empty()) {
        auto [dis, u] = q.top();
        q.pop();
        if (dis > dist[u]) continue;
        
        for (auto& [v, w] : g[u]) {
            if (dist[v] > dis + w) {
                dist[v] = dis + w;
                q.push({dist[v], v});
            }
        }
    }
}

signed main() {
    
    int n, m, tq;
    cin >> n >> m >> tq;
    
    while (m--) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        cash_g[u].emplace_back(v, c);
        lv_g[v].emplace_back(u, d); 
    }
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    djk(1, dist1, cash_g, n);
    djk(n, dist2, lv_g, n); 
    
    multiset<int> res;
    unordered_map<int, int> last_cost; 
    
    for (int i = 1; i <= n; ++i) {
        if (dist1[i] != inf && dist2[i] != inf) {
            int cost = dist1[i] + (dist2[i] + a[i] - 1) / a[i];
            res.insert(cost);
            last_cost[i] = cost;
        }
    }
    
    while (tq--) {
        int x, new_a;
        cin >> x >> new_a;
        
        if (last_cost.count(x)) {
            res.erase(res.find(last_cost[x]));
        }
        
        a[x] = new_a;
        if (dist1[x] != inf && dist2[x] != inf) {
            int new_cost = dist1[x] + (dist2[x] + a[x] - 1) / a[x];
            res.insert(new_cost);
            last_cost[x] = new_cost;
        }
        
        cout << *res.begin() << "\n";
    }
    return 0;
}
