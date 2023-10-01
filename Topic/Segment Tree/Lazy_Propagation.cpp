#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

class ST {

public:
    vector<int> seg, lazy;
    
    ST(int n) {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, vector<int> &a) {
        if(low == high) {
            seg[ind] = a[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);

        // When returning from funcion call update SegTree
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int low, int high, int l, int r, int val) {

        // Upadate the previous remaining updates
        // and propagate downwards
        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            // Propagaate the lazy updates downward
            // for the remainng nodes to be updated
            if(high != low) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // No overlap [l r low high] or [low high l r]
        if(l > high || r < low) return;

        // Complete overlap [l low high r]
        if(l <= low && r >= high) {
            seg[ind] += (high - low + 1) * val;

            // If children exixts
            if(high != low) {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        // Partial overlap
        int mid = low + (high - low) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }


    int query(int ind, int low, int high, int l, int r) {

        // If Upadates is remaining
        // Upadate it!!!
        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            // If children exists propagate downwards
            if(high != low) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // No Overleap
        // [low high] [l r] or [l r] [low high]
        // Should not contribute in our Answer
        if(l > high || r < low) return 0;

        // Complete Overleap
        // [l low high r]
        else if(l <= low && r >= high) return seg[ind];

        // Partial Overleap
        // Go left + Go right
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};


void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(int &x : v) cin>>x;
    ST st(n);
    st.build(0, 0, n - 1, v);

    int q; cin>>q;
    while(q--) {
        int type; cin>>type;
        if(type == 1) {
            int l, r; cin>>l>>r;
            cout<<st.query(0, 0, n - 1, l, r)<<endl;
        } else {
            int l, r, val; cin>>l>>r>>val;
            st.update(0, 0, n - 1, l, r, val);
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
i/p: 5
     1 2 3 4 5
     3
     1 0 4
     2 1 3 2
     1 0 4
o/p: 15
     21
*/