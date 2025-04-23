#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5;

double an[N];

void solve() {
    vector<double> nums;
    char comma;
    double num;


    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == ',') cin.ignore();
    }

   
    int cnt = 0;
    double sum = 0;
    for (int i = 0; i < nums.size(); i += 2) {
        if (i + 1 >= nums.size()) break;
        double a = nums[i];
        cnt++;
        an[cnt] = a;
        sum += a;
    }

   
    sort(an + 1, an + 1 + cnt);
    sum -= an[1] + an[cnt]; 

    cout  << an[cnt - 1] << endl;
    cout  << an[2] << endl;
    printf("%.2lf\n", sum / (cnt - 2));
}

signed main() {
    int t = 1;
    
    while (t--) solve();
}
