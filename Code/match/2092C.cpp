#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int inf = 1e18;

void solve()
{
    // C. Asuna and the Mosquitoes
    int n;
    cin >> n;
    int sum = 0;
    int jisum = 0;
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        (a % 2 == 1) ? jisum += 1 : jisum += 0;
        ans = max(ans, a);
    }
    if (jisum == n || jisum == 0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << sum - jisum + 1 << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}