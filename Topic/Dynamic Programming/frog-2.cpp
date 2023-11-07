#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<int> dp, h;

int func(int n, int k) {
    if(n == 1) return 0;
    int cost = INT_MAX;
    if(dp[n] != -1) return dp[n];
    
    //ways
    // for frog-2 run a loop for k
    for(int i = 1; i <= k; i++) {
        if(n - i >= 1)
            cost = min(cost, func(n - i, k) + abs(h[n] - h[n - i]));
    }
    return dp[n] = cost;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;
    h.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) cin>>h[i];

    ///TOP-DOWN Approch
    dp.resize(n + 1, -1);
    cout << func(n, k) << endl;
}

/*
i/p: 5 3
     10 30 40 50 20
o/p: 30
*/