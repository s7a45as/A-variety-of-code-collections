#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


vector<int> v_max;
int vv_max = 0;

int getNum(string a, int num) {
    if (a.size() == 1) {
        return num;
    }
    int t = 1;
    for (size_t i = 0; i < a.size(); i++) { 
        int ta = a[i] - '0';
        t *= ta;
    }
    string str = std::to_string(t);  
    num++;
    return getNum(str, num);         
}

void solve() {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        string str = std::to_string(i);  
        int tmp = getNum(str, 0);
        if (vv_max < tmp) {
            v_max.clear();
            vv_max = tmp;
            v_max.push_back(i);
        } else if (vv_max == tmp) {
            v_max.push_back(i);
        }
    }
    cout << vv_max << endl;
    for(auto p:v_max){
    	cout<<p<<" ";
    	
	
	}
	cout<<endl;
	
}

signed main() {
    solve();
}
