#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> post, in, level(100000, -1);
void pre(int root,int start,int end,int index) //rootΪ���ں��������е�λ�� start endΪ���������������еķ�Χ
{
	if(start>end) return ;//�ݹ���� 
	int i=start;
	while(i<end&&in[i]!=post[root]) i++;//Ѱ�Ҹ��������е�λ�� �����ָ�������� Ϊɶ����<= 
	level[index]=post[root];
	pre(root-(end-i)-1,start,i-1,2*index+1);//���������� root-(end-i)-1�� ��ȥ�����������������������ĸ���λ�� 
	pre(root-1,i+1,end,2*index+2);//���������� root-1���������ĸ��ڵ�λ�� 
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

