#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void ternarySearch(vector<int>& v, int x) {
    int l = 0, r = v.size() - 1;
    while(l <= r) {
        int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if(v[m1] == x || v[m2] == x) {
            cout<<"Found\n";
            return;
        }
        if(x < v[m1]) r = m1 - 1;
        else if(x > v[m2]) l = m2 + 1;
        else {l = m1 + 1; r = m2 - 1;}
    }
    cout<<"Not Found\n";
}

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    ternarySearch(v, k);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 5 3
     1 2 3 4 5
o/p: Found
*/