#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n;
const int N=1e6;

int pre[N];
int mid[N];
vector<int>ans;
struct node{
	int l=0;
	int r=0;
	
}t[N];
/**  
 * 根据中序和前序遍历序列构建二叉树
 * @param l1 中序遍历序列的起始下标
 * @param l2 中序遍历序列的结束下标
 * @param r1 前序遍历序列的起始下标
 * @param r2 前序遍历序列的结束下标
 * @return 当前子树的根节点值
 */
int build(int l1,int l2,int r1,int r2){
	if(l1>l2)return 0;
	int root=pre[r1];
	int p=l1;
	while(mid[p]!=root)p++;
	int cnt=p-l1;
	t[root].l=build(l1,p-1,r1+1,r1+cnt);
	t[root].r=build(p+1,l2,r1+cnt+1,r2);
	return root;
	
	
}
void bfs(int root){
	queue<int>q;
	q.push(root);
	ans.push_back(root);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(t[u].r!=0){
			ans.push_back(t[u].r);
			q.push(t[u].r);
			
		}if(t[u].l!=0) {
			ans.push_back(t[u].l);
			q.push(t[u].l);
			
		}
	}
}
void solve() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>mid[i];
	for(int i=1;i<=n;i++)cin>>pre[i];
	build(1,n,1,n);
	bfs(pre[1]);
	for(int i=0;i<ans.size();i++){
		if(i!=ans.size()-1){
			cout<<ans[i]<<" ";
			
		}else cout<<ans[i]<<endl;
		
	}


}

signed main() {

    int testCases = 1;
    while (testCases--) solve();
}
