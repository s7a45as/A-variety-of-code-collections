// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// struct Monster {
//     int h, p;
//     bool operator<(const Monster& other) const { 
//         return p > other.p; 
//     }
// };

// void solve() {
//     int n, k;
//     cin >> n >> k;
//     vector<Monster> mons(n);
    
//     for (int i = 0; i < n; i++) cin >> mons[i].h;
//     for (int i = 0; i < n; i++) cin >> mons[i].p;
    
//     priority_queue<Monster> pq;
//     for (auto& m : mons) pq.push(m);

//     int damage = 0;
//     while (k > 0 && !pq.empty()) {
//         damage += k; 
        
     
//         while (!pq.empty() && pq.top().h <= damage)
//             pq.pop();
        
//         if (!pq.empty()) 
//             k -= pq.top().p; 
//         else 
//             break;
        
//         if (k <= 0) break;
//     }

//     cout << (pq.empty() ? "YES" : "NO") << endl;
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t; cin >> t;
//     while (t--) solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int inf = 1e18;
struct node{
    int a,b;
    bool operator<(const node&t)const {
        return b>t.b;

    }
};

const int N=1e6;
int s[N];
int x[N];

void solve(){
       int n,k;
    priority_queue<node>q;
     while(!q.empty()){
        auto p=q.top();
      
        q.pop();

    }
 
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s[i];


    }
    for(int i=1;i<=n;i++){
        cin>>x[i];
        

    }



    for(int i=1;i<=n;i++){
        node tmp;
        tmp.a=s[i];
        tmp.b=x[i];
        q.push(tmp);

        

    }



   
    int cur=0;

    while(!q.empty()&&k>0){
        cur+=k;
        while(!q.empty()&&q.top().a<=cur)q.pop();

        if(!q.empty())k-=q.top().b;
        else break;

        if(k<=0)break;

        

    }
    cout<<(q.empty()?"YES":"NO")<<endl;


    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}