#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e4+1012312;
vector<int>g[N];
vector<int>path;
vector<int>ans;
int max_depth=0;
int vis[N];

void dfs(int x,int depth){
  if(depth > max_depth || 
      (depth == max_depth && path < ans)) { 
        max_depth = depth;
        ans = path;
    }
    for(auto p:g[x]){
        path.push_back(p);
        dfs(p,depth+1);
        path.pop_back();
        
    }
}




signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a;
            cin>>a;
            g[i].push_back(a);
            vis[a]=1;
            
        }
    }
    int start=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            start=i;
            break;
            
        }
    }
    path.push_back(start);
    dfs(start,1);
    
    cout<<max_depth<<endl;
    for(int i=0;i<ans.size();i++){
        if(i==ans.size()-1)cout<<ans[i];
        else cout<<ans[i]<<" ";
        
    }
    
}
