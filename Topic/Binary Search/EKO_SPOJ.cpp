#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int N = 1e6+10;
ll n, m;
vector<ll> trees(N);

bool isWoodSufficient(ll h) {
    ll wood = 0;
    for(int i = 0; i < n; i++) {
        wood += max(0ll,trees[i] - h);
    }
    return wood >= m;
}

 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>trees[i];

    ll l = 0, r = 1e9+10, mid, ans = -1;

    while(l <= r) {
        mid = l + (r - l) / 2;
        if(isWoodSufficient(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    cout<<ans<<endl;
    
    return 0;
}





/*
i/p: 4 7
     20 15 10 17
o/p: 15
*/