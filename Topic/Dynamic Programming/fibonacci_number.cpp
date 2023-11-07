#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<int> dp;

// // Brute-force Approch
// int fibo(int n) {
//     if (n <= 1) return n;
//     return fibo(n - 1) + fibo(n - 2);
// }

// DP Approch
int fibo(int n) {
    if (n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--) {
        int n;
        cin >> n;
        if(n <= 1) {cout<<n<<endl; continue; }
        
        ///TOP-DOWN Approch
        // dp.resize(n + 1, -1);
        // cout << fibo(n) << endl;

        ///BOTTOM-UP Approch
        // dp.resize(n + 1, -1);
        // dp[0] = 0, dp[1] = 1;
        // for(int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
        // cout<<dp[n]<<endl;

        ///Memory Optimization Approch
        int a = 0, b = 1;
        for(int i = 2; i <= n; i++) {
            int tmp = b;
            b += a;
            a = tmp;
        }
        cout<<b<<endl;
    }
}

/*
i/p: 4
o/p: 3
*/