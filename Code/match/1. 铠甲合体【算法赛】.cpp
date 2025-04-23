#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
long long b[N];
map < long long , long long , greater<long long> > p; 
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    long long a;
    cin >> a;
    p[a]++;
  }
  for(int i=1;i<=m;i++) cin>>b[i];
  for(int i=1;i<=m;i++)
  {  
    int ans = 0;
    for(auto t : p)
    {
    	int num=t.second;
    	int x= t.first;
    	
      ans += min(b[i] / x,num);
      b[i] -= x * min(b[i] / x,num);
      if(b[i]==0)
      {
        cout<<ans<<" ";
        break;
      }
    }
    if(b[i] > 0) cout << -1 << " ";
  }
  return 0;
}
