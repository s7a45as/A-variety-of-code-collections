#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> post, in, level(100000, -1);
void pre(int root,int start,int end,int index) //root为根在后序序列中的位置 start end为该树在中序序列中的范围
{
	if(start>end) return ;//递归结束 
	int i=start;
	while(i<end&&in[i]!=post[root]) i++;//寻找根在中序中的位置 将树分割成两部分 为啥不是<= 
	level[index]=post[root];
	pre(root-(end-i)-1,start,i-1,2*index+1);//遍历左子树 root-(end-i)-1即 减去右子树结点个数就是左子树的根的位置 
	pre(root-1,i+1,end,2*index+2);//遍历右子树 root-1即右子树的根节点位置 
 } 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		post.push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		in.push_back(a);
	}
	pre(n-1,0,n-1,0);
	for(int i=0;i<level.size();i++)
	{
		if(level[i]!=-1)
		{
			if(i!=0)
				cout<<" ";
			cout<<level[i];
		}
	}
} 

