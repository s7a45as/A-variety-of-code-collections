#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int maxn=11000002;
char datas[maxn<<1];
int p[maxn<<1], cnt, ans;
string s;
void change(){
	
	
    getline(cin, s); // 读取整行，包括空格
    datas[0] = '~';   // 开头特殊字符
    datas[1] = '|';   // 分隔符
    cnt = 1;         // 初始化下标
    for (char c : s) {
        datas[++cnt] = c;  // 插入字符
        datas[++cnt] = '|';// 插入分隔符
    }
}
void solve(){
	change();
	// cout<<cnt<<endl;
	
	int ans=0;
	for(int i=0;i<=cnt;i++){
		int j=i-1;
		int k=i+1;
//		int sum=1;
		
		while(j>=0&&k<=cnt){
			if(datas[j]==datas[k])
			{
//				cout<<s[i]<<" "<<s[j]<<"     "<<s[k]<<endl;
//				sum++;
				j--,k++;
			}else break;
			
		}
        
		ans=max(ans,k-j-1);
			
	}
    
  cout<<(ans)/2<<endl;
    
	
	
}
signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
}
