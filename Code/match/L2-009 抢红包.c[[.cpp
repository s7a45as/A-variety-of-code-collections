#include<iostream>
#include<algorithm>
using namespace std;
typedef struct {
	int num;//编号；
	double money;
	int count;//抢到红包的个数；
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
	for (int i = 0; i < N; i++) {//初始化结构体数组
		p[i].num = i + 1;
		p[i].count = 0;
		p[i].money = 0;
	}
	for (int i = 0; i < N; i++) {//输入发红包，抢红包数据
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
	sort(p, p + N, cmp);//排序
	for (int i = 0; i < N; i++) {//输出
		cout << p[i].num << " ";
		printf("%.2lf\n", p[i].money / 100);
	}
}
