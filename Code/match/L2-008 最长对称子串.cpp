#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int maxn=11000002;
char datas[maxn<<1];
int p[maxn<<1], cnt, ans;
string s;
void change(){
	
	
    getline(cin, s); // ��ȡ���У������ո�
    datas[0] = '~';   // ��ͷ�����ַ�
    datas[1] = '|';   // �ָ���
    cnt = 1;         // ��ʼ���±�
    for (char c : s) {
        datas[++cnt] = c;  // �����ַ�
        datas[++cnt] = '|';// ����ָ���
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
