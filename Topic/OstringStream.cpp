#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

 
void solve() {
    int n; cin>>n;
    ostringstream str1;
    str1<<n;
    string s = str1.str();
    cout<<s<<endl;
    cout<<s[0]<<" "<<s[3]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1; cin>>t;
    while(t--) {
        solve();
    }
}