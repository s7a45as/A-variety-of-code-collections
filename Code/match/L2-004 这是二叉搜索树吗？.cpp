using namespace std;
#include <iostream>
#include <cstdio>
#include <vector>

const int maxn = 1010;
int n, flag = false;
int pr[maxn];

vector<int>v;

void find(int l, int r) {
	if (l > r)return;
	int tr = r, tl = l + 1;
	if (!flag)//检查是否是二叉搜索树
	{
		while (tl <= r && pr[tl] < pr[l])tl++;//因为要检索的是节点的子树，tl=r时，pr[tl]也是节点的子树，故可以取等；同理，tr!=l,下面那个while的条件不能取等
		while (tr > l && pr[tr] >= pr[l])tr--;//右子树中所有结点的键值大于等于该结点的键值；
	}
	else//检查是否是镜面二叉搜素树
	{
		while (tl <= r && pr[tl] >= pr[l])tl++;
		while (tr > l && pr[tr] < pr[l])tr--;
	}
	if (tl - tr != 1)return;
	find(l + 1, tr);//遍历左子树
	find(tl, r);//遍历右子树
	v.push_back(pr[l]);//因为要求的是后序遍历输出，所以要先遍历左子树再遍历右子树
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> pr[i];
	find(0, n - 1);//检查是否是二叉搜索树
	if (v.size() != n)//不是二叉搜索树
	{
		v.clear();//清空vector
		flag = 1;
		find(0, n - 1);//检查是否是镜面二叉搜索树
	}
	if (v.size() != n)cout << "NO" << endl; 
	else
	{
		cout << "YES" << endl << v.front();
		for (int i = 1; i < v.size(); i++)cout << " " << v[i];
		cout << endl;
	}
}


