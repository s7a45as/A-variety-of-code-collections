#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> post, in; // �洢����������������
vector<int> level(100000, -1); // �������飬��ʼ��Ϊ-1����Ŀ��֤���ֵΪ��������

/**
 * ���ݺ�������򹹽������������������������
 * @param root ��ǰ�������ڵ��ں��������е��±�λ��
 * @param start ��ǰ���������������е���ʼ�±�
 * @param end ��ǰ���������������еĽ����±�
 * @param index ��ǰ�ڵ��ڲ��������еĴ洢λ�ã���ȫ��������ŷ�ʽ��
 */
void pre(int root, int start, int end, int index) {
    if(start > end) return; // �ݹ���ֹ����Ч����
    
    // �����������ж�λ���ڵ�λ��
    int i = start;
    while(i < end && in[i] != post[root]) i++; // ����ʱiָ����ڵ�
    
    // ����ǰ���ڵ�ֵ����������飨����ȫ������λ�ô洢��
    level[index] = post[root];
    
    /* �������нṹ: [������][������][��]
       ��������λ�ü���: 
       root - (�����������) - 1 
       = root - (end - i) -1
       ���������������������[i+1, end]ȷ��
    */
    pre(root - (end - i) - 1, start, i-1, 2*index+1); // �ݹ鴦��������
    
    /* ��������λ�ü���: 
       �����н����Ÿ��ڵ��ǰһ��λ��
       = root -1
    */
    pre(root -1, i+1, end, 2*index+2); // �ݹ鴦��������
}

int main() {
    int n;
    scanf("%d", &n);
    
    // ��ȡ��������
    for(int i=0; i<n; i++) {
        int a; scanf("%d", &a);
        post.push_back(a);
    }
    
    // ��ȡ��������
    for(int i=0; i<n; i++) {
        int a; scanf("%d", &a);
        in.push_back(a);
    }
    
    // �Ӻ������Ԫ�أ��ܸ�����ʼ�ݹ鹹�������������0��ʼ���
    pre(n-1, 0, n-1, 0);
    
    // ����������У������սڵ㣩
    bool first = true;
    for(int num : level) {
        if(num != -1) {
            if(!first) cout << " ";
            cout << num;
            first = false;
        }
    }
    return 0;
}
