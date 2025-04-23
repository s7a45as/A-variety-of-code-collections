#include<bits/stdc++.h>
using namespace std;
#define int long long // ʹ��long long����
#define endl '\n'     // ���з�
const int maxn=11000002; // ������ݹ�ģ���㹻����1e7�����ַ�����
char datas[maxn<<1];    // Ԥ�������ַ������飨ԭ�ַ������ȵ�����+3��
int p[maxn<<1], cnt, ans; // p����洢���İ뾶��cntΪԤ����󳤶ȣ�ans��¼���մ�
string s; // ԭʼ�����ַ���

// Ԥ����������ԭʼ�ַ���ת��Ϊ���ָ�������ʽ
void change() {
    getline(cin, s); // ��ȡ���У������ո�
    datas[0] = '~';   // �ڱ��ַ�����ֹԽ��Ƚ�
    datas[1] = '|';   // �ָ���
    cnt = 1;         // ��ʼ����������1��ʼ��䣩
    
    // ����Ԥ�����ַ���������"abc"���~|a|b|c|
    for (char c : s) {
        datas[++cnt] = c;  // ����ԭ�ַ�
        datas[++cnt] = '|';// ÿ���ַ������ָ���
    }
}

void solve() {
    change(); // Ԥ�����ַ���
    
    ans = 0;  // ��ʼ������ĳ���
    int c = 0, r = 0; // c:��ǰ���ĵ㣬r:��ǰ�ұ߽�
    
    // Manacher�㷨����
    for (int i = 1; i <= cnt; ++i) {
        // ����i��������c�ľ���λ��
        int mirror = 2 * c - i;
        
        // ���öԳ��Կ��ٳ�ʼ��p[i]
        if (i < r) {
            // ȡ����뾶�͵��ұ߽�Ľ�Сֵ��ȷ����������֪��Χ
            p[i] = min(r - i, p[mirror]);
        } else {
            p[i] = 1; // �����뾶Ϊ1�������ַ���
        }
        
        // ������չ������������İ뾶
        while (i + p[i] <= cnt && i - p[i] >= 0 && 
               datas[i + p[i]] == datas[i - p[i]]) {
            p[i]++;
        }
        
        // �������һ��ı߽�����ĵ�
        if (i + p[i] > r) {
            c = i;          // �µ����ĵ�
            r = i + p[i];   // �µ��ұ߽�
        }
        
        // ����ȫ�����ֵ
        if (p[i] > ans) {
            ans = p[i];
        }
    }
    
    // �𰸴����뾶-1����ԭ�ַ�������ĳ���
    cout << ans - 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false); // ����C�������ͬ��
    cin.tie(nullptr);            // ���cin��cout�İ�
    int t = 1;
    // cin >> t;                 // ���������ʱ����
    while (t--) solve();
}
