#include<bits/stdc++.h>
using namespace std;
const int N=1e7;

struct node{
	char character;
	int num;
	
}e[N];
bool cmp(node a,node b)
{
	if(a.num==b.num){
		return a.character<b.character;
		
	}
	return a.num>b.num;
	 
}
int main(){
	string s;
	cin>>s;

	for(int i=0;i<s.size();i++){
		e[s[i]].character=s[i];
		e[s[i]].num++;
		
	}
	sort(e,e+50000,cmp);
		int maxx=e[0].num;
		cout<<e[0].character<<endl;
		cout<<maxx<<endl;
		

	 
}
