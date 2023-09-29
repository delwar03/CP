#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;


//Inserting value in Vector
void Insert(vector<int> &v, int temp) {
    if(v.size() == 0 || v[v.size() - 1] <= temp) {
        v.push_back(temp);
        return;
    }
    int val = v[v.size() - 1];
    v.pop_back();
    Insert(v,temp);
    v.push_back(val);
}


//Sorting the Vector using recursion
void Sort(vector <int> &v) {
    if(v.size() == 1) return;
    int temp = v[v.size() - 1];
    v.pop_back();
    Sort(v);
    Insert(v,temp);
}

 
void solve() {
    int n; cin>>n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    Sort(v);
    for(auto i : v) cout<<i<<" ";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1; //cin>>t;
    while(t--) {
        solve();
    }
}






/*
i/p: 6
     5 8 3 13 15 4
op:  3 4 5 8 13 15 
*/