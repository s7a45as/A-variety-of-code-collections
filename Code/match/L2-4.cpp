// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// const int inf = 1e18;
// // L2-4 大众情人.cpp
// signed main()
// {
//     int a;
//     cin >> a;
//     vector<char> b(a + 1);

//     vector<vector<int>> c(a + 1, vector<int>(a + 1, inf));

//     for (int d = 1; d <= a; ++d)
//         c[d][d] = 0;

//     for (int d = 1; d <= a; ++d)
//     {
//         char e;
//         int f;
//         cin >> e >> f;
//         b[d] = e;
//         while (f--)
//         {
//             int g, h;
//             scanf("%lld:%lld", &g, &h);
//             c[d][g] = h;
//         }
//     }

//     for (int k = 1; k <= a; ++k)
//         for (int i = 1; i <= a; ++i)
//             for (int j = 1; j <= a; ++j)
//                 if (c[i][k] + c[k][j] < c[i][j])
//                     c[i][j] = c[i][k] + c[k][j];

//     vector<double> m(a + 1);
//     for (int i = 1; i <= a; ++i)
//     {
//         int n = 0;
//         for (int j = 1; j <= a; ++j)
//             if (i != j && b[i] != b[j])
//                 n = max(n, c[j][i]);
//         m[i] = 1.0 / n;
//     }

//     vector<int> o, p;
//     for (int q = 1; q <= a; ++q)
//         if (b[q] == 'F')
//             o.push_back(q);
//         else
//             p.push_back(q);

//     double r = -1;
//     vector<int> s;
//     for (auto t : o)
//     {
//         if (m[t] > r)
//         {
//             r = m[t];
//             s = {t};
//         }
//         else if (m[t] == r)
//             s.push_back(t);
//     }
//     sort(s.begin(), s.end());

//     double u = -1;
//     vector<int> v;
//     for (auto w : p)
//     {
//         if (m[w] > u)
//         {
//             u = m[w];
//             v = {w};
//         }
//         else if (m[w] == u)
//             v.push_back(w);
//     }
//     sort(v.begin(), v.end());

//     for (int x = 0; x < s.size(); ++x)
//     {
//         if (x)
//             cout << ' ';
//         cout << s[x];
//     }
//     cout << endl;
//     for (int x = 0; x < v.size(); ++x)
//     {
//         if (x)
//             cout << ' ';
//         cout << v[x];
//     }
//     cout << endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int inf = 1e18;
void solve(){}
signed main()
{
    
    int t=1;
    // cin>>t;
    while(t--)solve();


    return 0;
}