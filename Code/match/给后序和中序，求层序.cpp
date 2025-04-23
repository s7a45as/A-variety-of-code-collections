#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> post, in; // 存储后序和中序遍历序列
vector<int> level(100000, -1); // 层序数组，初始化为-1（题目保证结点值为正整数）

/**
 * 根据后序和中序构建二叉树，并按层序填充数组
 * @param root 当前子树根节点在后序序列中的下标位置
 * @param start 当前子树在中序序列中的起始下标
 * @param end 当前子树在中序序列中的结束下标
 * @param index 当前节点在层序数组中的存储位置（完全二叉树编号方式）
 */
void pre(int root, int start, int end, int index) {
    if(start > end) return; // 递归终止：无效区间
    
    // 在中序序列中定位根节点位置
    int i = start;
    while(i < end && in[i] != post[root]) i++; // 结束时i指向根节点
    
    // 将当前根节点值存入层序数组（按完全二叉树位置存储）
    level[index] = post[root];
    
    /* 后序序列结构: [左子树][右子树][根]
       左子树根位置计算: 
       root - (右子树结点数) - 1 
       = root - (end - i) -1
       右子树结点数由中序区间[i+1, end]确定
    */
    pre(root - (end - i) - 1, start, i-1, 2*index+1); // 递归处理左子树
    
    /* 右子树根位置计算: 
       后序中紧挨着根节点的前一个位置
       = root -1
    */
    pre(root -1, i+1, end, 2*index+2); // 递归处理右子树
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 读取后序序列
    for(int i=0; i<n; i++) {
        int a; scanf("%d", &a);
        post.push_back(a);
    }
    
    // 读取中序序列
    for(int i=0; i<n; i++) {
        int a; scanf("%d", &a);
        in.push_back(a);
    }
    
    // 从后序最后元素（总根）开始递归构建，层序数组从0开始填充
    pre(n-1, 0, n-1, 0);
    
    // 输出层序序列（跳过空节点）
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
