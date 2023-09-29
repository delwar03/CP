#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int a[100005];

//Algorithm of Merge :
void Merge(int l, int r, int mid) {

    int l_sz = mid - l + 1, r_sz = r - mid;
    int L[l_sz + 1], R[r_sz + 1];
    for(int i = 0; i < l_sz; i++) L[i] = a[l + i];
    for(int i = 0; i < r_sz; i++) R[i] = a[mid + 1 + i];

    L[l_sz] = R[r_sz] = INT_MAX;
    
    int l_i = 0, r_i = 0;
    for(int  i = l; i <= r; i++) {
        if(L[l_i] <= R[r_i]) a[i] = L[l_i++];
        else a[i] = R[r_i++];
    }
}


//Algorithm of Merge Sort:
void MergeSort(int l, int r) {
    if(l == r) return; /// Single Element is always sorted

    int mid = (r + l) / 2;
    MergeSort(l,mid);
    MergeSort(mid + 1,r);
    Merge(l,r,mid);
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n;
    
    for(int i = 0; i < n; i++) cin>>a[i];

    MergeSort(0,n-1);

    for(int i = 0; i < n; i++) cout<<a[i]<<" \n"[i == n - 1];

    
    return 0;
}