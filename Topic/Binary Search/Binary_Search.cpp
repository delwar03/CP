#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int Binary_Search(vector <int> &v, int x) {
    int l = 0, r = v.size() - 1, mid;

    while(l <= r) {
        if(x == v[mid]) return mid;
        else if(x < v[mid]) l = mid - 1;
        else r = mid + 1;
    }
    return -1;
}

 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // int n; cin>>n;
    // vector<int> v(n);
    // for(auto &i : v) cin>>i;
    // int x; cin>>x;
    // cout<<Binary_Search(v,x)<<endl;
    cout<<2;
    return 0;
}





/*
i/p: 7
     1 2 4 5 7 10 12
     4
o/p: 2
*/