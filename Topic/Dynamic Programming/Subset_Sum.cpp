#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

bool isPossible(int n, vector<int> &v, int sum) {
    bool dp[n + 1][sum + 1];
    for(int i = 0; i <= n; i++) dp[i][0] = true;
    for(int i = 0; i <= sum; i++) dp[0][i] = false;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j - v[i - 1] >= 0) dp[i][j] |= dp[i - 1][j - v[i - 1]];
        }
    }
    return dp[n][sum];
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int sum = 0;
    for(auto &x : v) {cin>>x; sum += x;}
    if(sum & 1) {cout<<"0\n"; return; }

    if(isPossible(n, v, sum / 2)) {
        
        for(int i = 0; i < n; i++) {
            vector<int> tmp;
            for(int j = 0; j < n; j++) {
                if(i ^ j) {
                    tmp.push_back(v[j]);
                }
            }
            int newSum = sum - v[i];
            if((newSum & 1) || (!isPossible(n - 1, tmp, newSum / 2))) {cout<<"1\n"<<i + 1<<endl; return; }
        }
    } else {
        cout<<"0\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 
