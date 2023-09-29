#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void print(int n) {
    if(n == 0) return;
    print(n - 1);
    cout<<n<<" ";
}


void solve() {

    int n; cin>>n;
    print(n);
}

 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1; //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}





/*
i/p: 12
o/p: 1 2 3 4 5 6 7 8 9 10 11 12
*/