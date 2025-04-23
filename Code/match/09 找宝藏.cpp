#include<bits/stdc++.h>
using namespace std;
const int N=2131;
int vis[N][N];
struct Node {
    int x, y;
};
void solve(){
      int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int sx = -1, sy = -1, tx = -1, ty = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'T') {
                tx = i;
                ty = j;
            }
        }
    }

    if (sx == -1 || sy == -1 || tx == -1 || ty == -1) {
        cout << "My God?" << endl;
        return ;
    }
    queue<Node> q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    bool found = false;
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();
        if (curr.x == tx && curr.y == ty) {
            found = true;
            break;
        }

       
        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '1' || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    cout << (found ? "My God!" : "My God?") << endl;
}
signed main() {
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        
    }
}
