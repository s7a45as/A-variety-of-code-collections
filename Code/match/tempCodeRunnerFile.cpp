#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int inf = 1e18;
const int MAXN = 1e6 + 5;
bool isPrime[MAXN]; 
int primes[MAXN];   
int cnt = 0;        
const int N=1e6; 

void GetPrime(int n) {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;  
    
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes[cnt++] = i;  
        }
       
        for (int j = 0; j < cnt && i * primes[j] <= n; ++j) {
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }
}
void solve(){
    // 
    int n;
    cin>>n;
  
    int ans=0;
    int p=upper_bound(primes,primes+cnt,n)-primes;
    ans+=p;
    


    for(int i=0;i<=cnt;i++){
        if(primes[i]>n)break;
        if(primes[i]==0)break;
        
        // ans++;
        ans+=max(((n/primes[i])-1LL),0LL);
        // cout<<"primes[i]   "<<primes[i]<<endl;
        
    }
    cout<<ans<<endl;

    
}

signed main() {
    ios::sync_with_stdio(false);
    GetPrime(N);
    cin.tie(0);
    int t=1;
    
 
    cin >> t;

    while(t--) solve();
    return 0;
}