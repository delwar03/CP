#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
vector<int> a, seg;

void build(int ind, int low, int high) {
    if(low == high) {
        seg[ind] = a[low];
        return;
    }

    int mid = low + (high - low) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);

    // When returning from funcion call update SegTree
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r) {

    // No Overleap
    // [low high] [l r] or [l r] [low high]
    if(l > high || r < low) return INT_MAX;

    // Complete Overleap
    // [l low high r]
    else if(l <= low && r >= high) return seg[ind];

    // Partial Overleap
    else {
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }
}


void update(int ind, int low, int high, int i, int val) {
    if(low == high) {
        seg[ind] = val;
        return;
    }
    int mid = low + (high - low) / 2;
    if(i <= mid) update(2 * ind + 1, low, mid, i, val);
    else update(2 * ind + 2, mid + 1, high, i, val);
    
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}


void solve() {
    int n; cin>>n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    seg.resize(4 * n + 1);
    build(0, 0, n - 1);

    int q; cin>>q;
    while(q--) {
        int type; cin>>type;
        if(type == 1) {
            int l, r; cin>>l>>r;
            cout<<query(0, 0, n - 1, l, r)<<endl;
        } else {
            int i, val; cin>>i>>val;
            update(0, 0, n - 1, i, val);
        }
    }
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
i/p: 7
     1 2 0 3 4 1 2
     5
     1 0 3
     2 2 4
     1 0 3
     2 5 10
     1 4 6
o/p: 0
     1
     2
*/