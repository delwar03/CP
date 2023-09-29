#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void Selection_Sort(int a[], int l, int r) {

    for(int i = l; i <= r; i++) {
        int min_idx = i;
        for(int j = i + 1; j <= r; j++) {
            if(a[j] < a[min_idx]) min_idx = j;
        }
        swap(a[i],a[min_idx]);
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n;
    int a[n+1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    Selection_Sort(a,1,n);

    for(int i = 1; i <= n; i++) cout<<a[i]<<" \n"[i == n];

    
    return 0;
}