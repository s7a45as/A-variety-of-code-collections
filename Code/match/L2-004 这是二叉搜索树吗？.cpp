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
	if (!flag)//����Ƿ��Ƕ���������
	{
		while (tl <= r && pr[tl] < pr[l])tl++;//��ΪҪ�������ǽڵ��������tl=rʱ��pr[tl]Ҳ�ǽڵ���������ʿ���ȡ�ȣ�ͬ��tr!=l,�����Ǹ�while����������ȡ��
		while (tr > l && pr[tr] >= pr[l])tr--;//�����������н��ļ�ֵ���ڵ��ڸý��ļ�ֵ��
	}
	else//����Ƿ��Ǿ������������
	{
		while (tl <= r && pr[tl] >= pr[l])tl++;
		while (tr > l && pr[tr] < pr[l])tr--;
	}
	if (tl - tr != 1)return;
	find(l + 1, tr);//����������
	find(tl, r);//����������
	v.push_back(pr[l]);//��ΪҪ����Ǻ���������������Ҫ�ȱ����������ٱ���������
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> pr[i];
	find(0, n - 1);//����Ƿ��Ƕ���������
	if (v.size() != n)//���Ƕ���������
	{
		v.clear();//���vector
		flag = 1;
		find(0, n - 1);//����Ƿ��Ǿ������������
	}
	if (v.size() != n)cout << "NO" << endl; 
	else
	{
		cout << "YES" << endl << v.front();
		for (int i = 1; i < v.size(); i++)cout << " " << v[i];
		cout << endl;
	}
}


