#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=1e5;

double an[N];

void solve(){
    double a;
    char b;
    double sum = 0;
    int cnt = 0;
    
    while (scanf("%lf %c", &a, &b) == 2) {
        cnt++;
        an[cnt] = a;
        sum += a;
    }
    
    sort(an + 1, an + 1 + cnt);
    sum -= an[1];  
    sum -= an[cnt];

    cout << an[cnt-1] << endl;
    cout << an[2] << endl;
    printf("%.2lf\n", sum / (cnt - 2));
}

signed main() {
    int t = 1;
    while (t--) solve();
    return 0;
}
