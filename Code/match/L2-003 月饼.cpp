#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6;
double d;
int n;
struct node{
	double w,v,d;
	int id;
	
	
}e[N];
bool cmp(node a ,node b){
	return a.d>b.d;
	
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>e[i].w;
	for(int i=1;i<=n;i++)cin>>e[i].v;
	for(int i=1;i<=n;i++)e[i].d=e[i].v/e[i].w,e[i].id=i;
	sort(e+1,e+1+n,cmp);
	double ans=0.0;
	
	for(int i=1;i<=n;i++){
		if(d<=0)break;
//		cout<<d<<endl;
		
		if(e[i].w<=d){
			d-=e[i].w;
			ans+=e[i].v;
//			cout<<"ans"<<ans<<endl;
			
			e[i].w-=e[i].w;
			
			
		}else{
			ans+=e[i].d*d;
			e[i].w-=d;
			d-=d;
			
//			cout<<"ans"<<ans<<endl;
			
		}
	}
	printf("%.2lf",ans);
	
	
	

}
signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
}
