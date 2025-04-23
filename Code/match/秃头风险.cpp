#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int n;
const int N=1e6;

signed main(){
  cin>>n;
  int ans=0;

  for(int i=1;i<=n;i++){
    int a;
    cin>>a;
    int tt=a*a;
    tt++;

    if(tt%2!=0)ans++;
    else if(int(sqrt(a))*int(sqrt(a))==a)ans++;

  }
  cout<<ans<<endl;


}
