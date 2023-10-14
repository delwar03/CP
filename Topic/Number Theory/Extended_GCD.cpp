#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

vector<int> e_gcd(int a, int b) {
        if(b == 0) return {1, 0, a};
        auto dash = e_gcd(b, a % b); // {x, y, gcd}
        return {dash[1], dash[0] - (a / b) * dash[1], dash[2]};
}

void solve() {
    // Given a, b
    // find the Integral solution of ax + by = gcd(a, b)
    // {x, y} = ?

    int a, b; cin>>a>>b;
    vector<int> sol = e_gcd(a, b); // {x, y, gcd}
    cout<<"x = "<<sol[0]<<", y = "<<sol[1]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 