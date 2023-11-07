#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<int> wt, val;
ll dp[105][100005];

ll func(int ind, int val_left) {
    if(val_left == 0) return 0;
    if(ind < 0) return 1e15;
    if(dp[ind][val_left] != -1) return dp[ind][val_left];

    // Don't choose item at ind
    ll ans = func(ind - 1, val_left);
    
    // Choose item at ind
    if(val_left - val[ind] >= 0)
        ans = min(ans, func(ind - 1, val_left - val[ind]) + wt[ind]);
    return dp[ind][val_left] = ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w; cin >> n >> w;
    val.resize(n);
    wt.resize(n);
    for(int i = 0; i < n; i++) cin>>wt[i]>>val[i];

    ///TOP-DOWN Approch
    memset(dp, -1, sizeof(dp));

    for(int i = 1e5; i >= 0; i--) {
        if(func(n - 1, i) <= w) {
            cout<<i<<endl;
            break;
        }
    }
}

/*
i/p: 1 1000000000
     1000000000 10
o/p: 10
*/