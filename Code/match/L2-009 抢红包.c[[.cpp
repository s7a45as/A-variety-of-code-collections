#include<iostream>
#include<algorithm>
using namespace std;
typedef struct {
	int num;//��ţ�
	double money;
	int count;//��������ĸ�����
}people;
bool cmp(people p1, people p2) {
	if (p1.money == p2.money) {
		if (p1.count == p2.count) {
			return p1.num < p1.num;
		}
		return p1.count > p2.count;
	}
	return p1.money > p2.money;
}
int main(void) {
	int N;
	cin >> N;
	people *p = new people[N];
	for (int i = 0; i < N; i++) {//��ʼ���ṹ������
		p[i].num = i + 1;
		p[i].count = 0;
		p[i].money = 0;
	}
	for (int i = 0; i < N; i++) {//���뷢��������������
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int m, money;
			cin >> m >> money;
			p[i].money -= money;
			p[m - 1].money += money;
			p[m - 1].count++;
		}
	}
	sort(p, p + N, cmp);//����
	for (int i = 0; i < N; i++) {//���
		cout << p[i].num << " ";
		printf("%.2lf\n", p[i].money / 100);
	}
}
