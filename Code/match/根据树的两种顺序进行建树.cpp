#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n; // �ڵ�����
int mid[35]; // �洢�����������
int pre[35]; // �洢ǰ���������
int v[35];   // ������飨ʵ���ڴ�����δʹ�õ����ܣ��ɺ��ԣ�
vector<int> ans; // �洢��α����Ľ��

// ���ڵ�ṹ�壬���������ӽڵ�
struct node{
    int l=0; // ���ӽڵ㣬Ĭ��Ϊ0��ʾ��
    int r=0; // ���ӽڵ�
}t[35]; // ʹ�ýڵ�ֵ��Ϊ����������t[root]��ʾֵΪroot�Ľڵ�

/**
 * ���������ǰ��������й���������
 * @param l1 ����������е���ʼ�±�
 * @param l2 ����������еĽ����±�
 * @param r1 ǰ��������е���ʼ�±�
 * @param r2 ǰ��������еĽ����±�
 * @return ��ǰ�����ĸ��ڵ�ֵ
 */
int build(int l1, int l2, int r1, int r2) {
    // �ݹ���ֹ�������������з�Χ��Ч
    if(l1 > l2) return 0;
    // ǰ�����еĵ�һ��Ԫ��Ϊ��ǰ�����ĸ�
    int root = pre[r1];
    // �������������ҵ�����λ��
    int p = l1;
    while(mid[p] != root) p++;
    // �����������Ľڵ���Ŀ
    int cnt = p - l1;
    // �ݹ鹹�����������������������ΧΪ[l1, p-1]��ǰ���Ӧ��ΧΪ[r1+1, r1+cnt]
    t[root].l = build(l1, p-1, r1+1, r1+cnt);
    // �ݹ鹹�����������������������ΧΪ[p+1, l2]��ǰ���Ӧ��ΧΪ[r1+cnt+1, r2]
    t[root].r = build(p+1, l2, r1+cnt+1, r2);
    return root;
}

/**
 * �����������ʵ�־����α������ҵ���
 * @param root ���ĸ��ڵ�ֵ
 */
void bfs(int root) {
    queue<int> q;
    q.push(root);
    ans.push_back(root);
    v[root] = 1; // ����ѷ��ʣ�ʵ�ʿ�ʡ�ԣ�
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        // ���������Һ���
        if(t[u].r != 0) { // ���ӽڵ����
            q.push(t[u].r);
            ans.push_back(t[u].r);
            v[t[u].r] = 1;
        }
        if(t[u].l != 0) { // ���ӽڵ����
            q.push(t[u].l);
            ans.push_back(t[u].l);
            v[t[u].l] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    // ��ȡ�����������
    for(int i = 1; i <= n; i++) cin >> mid[i];
    // ��ȡǰ���������
    for(int i = 1; i <= n; i++) cin >> pre[i];
    // ����������
    build(1, n, 1, n);
    // ���о����α���
    bfs(pre[1]); // ���ڵ�Ϊǰ��ĵ�һ��Ԫ��
    // ��������ĩβ�޿ո�
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
