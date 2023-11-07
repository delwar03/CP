#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<int> dp, h;

int func(int n, int k = 2) {
    if(n == 1) return 0;
    int cost = INT_MAX;
    if(dp[n] != -1) return dp[n];
    
    //ways
    for(int i = 1; i <= k; i++) {
        if(n - i >= 1)
            cost = min(cost, func(n - i) + abs(h[n] - h[n - i]));
    }
    return dp[n] = cost;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--) {
        int n; cin >> n;
        h.resize(n + 1, 0);
        for(int i = 1; i <= n; i++) cin>>h[i];

    //     ///TOP-DOWN Approch
    //     dp.assign(n + 1, -1);
    //     cout << func(n) << endl;
    // }

        ///BOTTOM-UP Approch
        dp.assign(n + 1, 0);
        for(int i = 2; i <= n; i++) {
            int left = dp[i - 1] + abs(h[i] - h[i - 1]);
            int right = INT32_MAX;
            if(i > 2) right = dp[i - 2] + abs(h[i] - h[i - 2]);
            dp[i] = min(left, right);
        }
        cout<<dp[n]<<endl;
    }   
}

/*
i/p: 4
     10 30 40 20
o/p: 30
*/