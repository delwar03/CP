#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<int> wt, val;
ll dp[105][100005];

ll func(int ind, int wt_left) {
    if(wt_left == 0) return 0;
    if(ind < 0) return 0;
    if(dp[ind][wt_left] != -1) return dp[ind][wt_left];
    
    // Don't choose item at ind
    ll ans = func(ind - 1, wt_left);

    // Choose item at ind
    if(wt_left - wt[ind] >= 0)
        ans = max(ans, func(ind - 1, wt_left - wt[ind]) + val[ind]);
    return dp[ind][wt_left] = ans;
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

    cout<<func(n - 1, w)<<endl;
}

/*
i/p: 3 8
     3 30
     4 50
     5 60
o/p: 90
*/