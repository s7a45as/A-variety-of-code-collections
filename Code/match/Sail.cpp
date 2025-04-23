#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int inf = 1e18;
int n;
int sx,sy,ex,ey;
int distan=inf;
// B. Sail-----https://codeforces.com/problemset/problem/298/B
bool check(int sx,int sy,int ex,int ey){
    int newdist=(ex-sx)*(ex-sx)+(ey-sy)*(ey-sy);
    if(newdist<distan){
        distan=newdist;
        return true;

    }
    return false;

}



void solve(){

 
    cin>>n;

 
    cin>>sx>>sy>>ex>>ey;
    string s;
    cin>>s;
    check(sx,sy,ex,ey);
    int xx=sx;
    int yy=sy;
    int ans=0;
    int bo=0;

    for(auto p:s){
        int xxx,yyy;
        ans++;


        if(p=='S'){
            xxx=xx;
            yyy=yy-1;
            
        }else if(p=='N'){
            xxx=xx;
            yyy=yy+1;

        }else if(p=='W'){
            xxx=xx-1;
            yyy=yy;

        }else if(p=='E'){
            xxx=xx+1;
            yyy=yy;

        }
        if(xxx==ex&&yyy==ey){
            bo=1;

            break;

        }


        if(!check(xxx,yyy,ex,ey)){
            xxx=xx;
            yyy=yy;

        }else{
            xx=xxx;
            yy=yyy;

        }
    }
    if(bo)
    cout<<ans<<endl;
    else cout<<-1<<endl;



}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}