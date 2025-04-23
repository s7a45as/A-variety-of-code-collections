#include<bits/stdc++.h>
using namespace std;
#define int long long // 使用long long类型
#define endl '\n'     // 换行符
const int maxn=11000002; // 最大数据规模（足够处理1e7级别字符串）
char datas[maxn<<1];    // 预处理后的字符串数组（原字符串长度的两倍+3）
int p[maxn<<1], cnt, ans; // p数组存储回文半径，cnt为预处理后长度，ans记录最终答案
string s; // 原始输入字符串

// 预处理函数：将原始字符串转换为带分隔符的形式
void change() {
    getline(cin, s); // 读取整行（包含空格）
    datas[0] = '~';   // 哨兵字符，防止越界比较
    datas[1] = '|';   // 分隔符
    cnt = 1;         // 初始化索引（从1开始填充）
    
    // 构造预处理字符串，例如"abc"变成~|a|b|c|
    for (char c : s) {
        datas[++cnt] = c;  // 插入原字符
        datas[++cnt] = '|';// 每个字符后插入分隔符
    }
}

void solve() {
    change(); // 预处理字符串
    
    ans = 0;  // 初始化最长回文长度
    int c = 0, r = 0; // c:当前中心点，r:当前右边界
    
    // Manacher算法核心
    for (int i = 1; i <= cnt; ++i) {
        // 计算i关于中心c的镜像位置
        int mirror = 2 * c - i;
        
        // 利用对称性快速初始化p[i]
        if (i < r) {
            // 取镜像半径和到右边界的较小值，确保不超过已知范围
            p[i] = min(r - i, p[mirror]);
        } else {
            p[i] = 1; // 基础半径为1（单个字符）
        }
        
        // 中心扩展：尝试扩大回文半径
        while (i + p[i] <= cnt && i - p[i] >= 0 && 
               datas[i + p[i]] == datas[i - p[i]]) {
            p[i]++;
        }
        
        // 更新最右回文边界和中心点
        if (i + p[i] > r) {
            c = i;          // 新的中心点
            r = i + p[i];   // 新的右边界
        }
        
        // 更新全局最大值
        if (p[i] > ans) {
            ans = p[i];
        }
    }
    
    // 答案处理：半径-1等于原字符串最长回文长度
    cout << ans - 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false); // 禁用C输入输出同步
    cin.tie(nullptr);            // 解除cin与cout的绑定
    int t = 1;
    // cin >> t;                 // 多测试用例时启用
    while (t--) solve();
}
