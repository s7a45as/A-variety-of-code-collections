#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int x, n;
    cin >> x >> n;
    int max_g = x / n;  
    vector<int> divisors;


    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            divisors.push_back(i);
            if (i != x / i) {
                divisors.push_back(x / i);
            }
        }
    }

 
    sort(divisors.begin(), divisors.end(), greater<int>());


    int ans = 0;
    for (int g : divisors) {
        if (g <= max_g) {
            ans = g;
            break;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}