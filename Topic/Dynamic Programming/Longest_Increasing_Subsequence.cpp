#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<int> dp, v;

int LIS(int i) {
    if(dp[i] != -1) return dp[i];
    int ans = 1;
    for(int j = i - 1; j >= 1; j--) {
        if(v[j] < v[i]) ans = max(ans, 1 + LIS(j));
    }
    return dp[i] = ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    v.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) cin>>v[i];

    ///TOP-DOWN Approch
    dp.resize(n + 1, -1);
    int ans = 1;
    for(int i = 1; i <= n; i++) ans = max(ans, LIS(i));
    cout<<ans<<endl;
}

/*
i/p: 8
     10 9 2 5 3 7 101 18
     6
     0 1 0 3 2 3
o/p: 4
     4
*/