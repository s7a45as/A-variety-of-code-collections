#include<bits/stdc++.h>
using namespace std;
const int N=1e7;

void solve(){
		double n;
		cin>>n;
		double ji=0;
		double you=0;
		
		for(int i=1;i<=n;i++){
			double a;
			cin>>a;
			if(a>=60){
				ji++;
				
			}
			if(a>=85){
				you++;
				
			}
		} 
	printf("%.0f%%\n",ji/n*100.0);
	printf("%.0f%%\n",you/n*100.0);
}	
int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	
	 
}
