#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int inf = 1e18;

const int N=5000;
char g[N][N];

void solve(){
    // L1-039 古风排版
    int n;
    cin>>n;
    
    // getchar();
    for(int i=1;i<=n+1000;i++){
        for(int j=1;j<=n+1000;j++){
            g[i][j]=' ';
        }
    }
    cin.ignore();
    string s;
    getline(cin,s);

    int lie=n+1000;
    int ends=n+1000;

    int cur=1;
    // cout<<s<<endl;
    for(int i=0;i<s.size();i++){
        if(i%n==0&&i!=0){
            cur=1;
            lie--;
            // cout<<"lie "<<lie<<endl;
        }
        g[cur][lie]=s[i];
        cur++;
        

    }
 
    for(int i=1; i<=n; i++){
        for(int j=lie; j<=ends; j++){ 
            cout << g[i][j];
        }
        cout << endl;
    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
/*


"请开发一款基于微信小程序的数独游戏，要求支持多种模式（2x2、3x3、4x4、5x5、6x6宫格）及难度分级（简单25%、中等10%、困难5%初始数字），采用模块化架构设计以保障扩展性。核心功能需包含：1）动态宫格生成系统，通过预定义blockIndexList实现不同尺寸宫格的坐标映射，并采用回溯算法生成唯一解终盘；2）难度控制系统，通过'挖洞'算法按比例移除数字，结合拉斯维加斯随机算法保障题目合法性；3）交互式UI组件，采用Canvas动态渲染棋盘并实现触摸事件绑定，底部设置数字选择面板；4）状态管理模块，通过独立Model类维护棋盘数据、计时器、游戏进度，与View层解耦；5）扩展接口层，预留GameModeManager和DifficultyManager抽象类，支持未来新增模式（如锯齿宫格）和自定义难度参数；建议补充：a) 增加数独规则验证模块，通过行/列/宫三重校验算法；b) 引入对称变换机制提升题目多样性；c) 设计成就系统和数据统计模块，利用wx.setStorageSync实现本地化存储；d) 预埋事件总线机制，便于后期添加音效、动画特效和社交分享功能；e) 采用工厂模式封装数独生成器，隔离数独核心算法与界面逻辑。要求代码遵循SOLID原则，关键模块配置单元测试用例，并为AI解题助手、多语言支持等远期功能预留接口。" 



*/