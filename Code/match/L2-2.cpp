#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 12;
struct node
{
    string s1;
    string s2;
    bool operator<(node a) const
    {
        return s1 != a.s1 ? s1 < a.s1 : s2 < a.s2;
    }
} e[N];
int vis[N];
vector<string> ans;

signed main()
{
    // string s1="00:00:00";
    // string s2="01:00:05";
    // if(s1<s2)cout<<"1"<<endl;
    int n;
    cin >> n;
    vector<node> v(n);
    getchar();
    string s1;

    for (int i = 1; i <= n; i++)
    {
        getline(cin, s1);
        // cout<<s1<<endl;
        node a;
        string s2 = s1.substr(0, s1.find("-") - 1);
        // cout<<s2<<endl;
        string s3 = s1.substr(s1.find("-") + 2);
        // cout<<s3<<endl;
        a.s1 = s2;
        a.s2 = s3;
        e[i].s1 = s2;
        e[i].s2 = s3;
    }

    sort(e + 1, e + 1 + n);
    int bo = 0;

    // for(int i=1;i<=n;i++){
    //     cout<<" "<<e[i].s1<<" "<<e[i].s2<<endl;

    // }

    int cnt = 0;

    for (int i = 1; i < n; i++)
    {
        if (e[i].s2 != e[i + 1].s1)
        {
            // cout<<e[i].s2<<" - "<<e[i+1].s1<<endl;
            string s5 = e[i].s2 + " - " + e[i + 1].s1;
            ans.push_back(s5);
        }
    }
    string s6;
    int start = 1;

    if (e[1].s1 != "00:00:00")
    {
        e[0].s1 = "00:00:00";
        e[0].s2 = e[1].s1;
        vis[0] = 1;
        s6 = "00:00:00 - " + e[1].s1;
        ans.push_back(s6);
        start = 0;
    }
    if (e[n].s2 != "23:59:59")
    {
        e[n + 1].s1 = e[n].s2;
        e[n + 1].s2 = "23:59:59";
        vis[n + 1] = 1;
        string s5 = e[n].s2 + " - " + "23:59:59";
        ans.push_back(s5);
    
    }

    for(auto p:ans){
        cout<<p<<endl;
        
    }






    // for(int i=start;i<=cnt;i++){

    //         cout<<ans[i]<<endl;

    // }
}