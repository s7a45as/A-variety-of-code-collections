#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n; // 节点总数
int mid[35]; // 存储中序遍历序列
int pre[35]; // 存储前序遍历序列
int v[35];   // 标记数组（实际在代码中未使用到功能，可忽略）
vector<int> ans; // 存储层次遍历的结果

// 树节点结构体，包含左右子节点
struct node{
    int l=0; // 左子节点，默认为0表示空
    int r=0; // 右子节点
}t[35]; // 使用节点值作为索引，例如t[root]表示值为root的节点

/**
 * 根据中序和前序遍历序列构建二叉树
 * @param l1 中序遍历序列的起始下标
 * @param l2 中序遍历序列的结束下标
 * @param r1 前序遍历序列的起始下标
 * @param r2 前序遍历序列的结束下标
 * @return 当前子树的根节点值
 */
int build(int l1, int l2, int r1, int r2) {
    // 递归终止条件：中序序列范围无效
    if(l1 > l2) return 0;
    // 前序序列的第一个元素为当前子树的根
    int root = pre[r1];
    // 在中序序列中找到根的位置
    int p = l1;
    while(mid[p] != root) p++;
    // 计算左子树的节点数目
    int cnt = p - l1;
    // 递归构建左子树：中序的左子树范围为[l1, p-1]，前序对应范围为[r1+1, r1+cnt]
    t[root].l = build(l1, p-1, r1+1, r1+cnt);
    // 递归构建右子树：中序的右子树范围为[p+1, l2]，前序对应范围为[r1+cnt+1, r2]
    t[root].r = build(p+1, l2, r1+cnt+1, r2);
    return root;
}

/**
 * 广度优先搜索实现镜像层次遍历（右到左）
 * @param root 树的根节点值
 */
void bfs(int root) {
    queue<int> q;
    q.push(root);
    ans.push_back(root);
    v[root] = 1; // 标记已访问（实际可省略）
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        // 镜像处理：先右后左
        if(t[u].r != 0) { // 右子节点存在
            q.push(t[u].r);
            ans.push_back(t[u].r);
            v[t[u].r] = 1;
        }
        if(t[u].l != 0) { // 左子节点存在
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
    // 读取中序遍历序列
    for(int i = 1; i <= n; i++) cin >> mid[i];
    // 读取前序遍历序列
    for(int i = 1; i <= n; i++) cin >> pre[i];
    // 构建二叉树
    build(1, n, 1, n);
    // 进行镜像层次遍历
    bfs(pre[1]); // 根节点为前序的第一个元素
    // 输出结果，末尾无空格
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
