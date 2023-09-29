#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1; //cin>>t;
    while(t--) {
        int n; cin>>n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) cin>>v[i];
        
        for(int i = 0; i < n; i++) {
        	for(int j = i + 1; j < n; j++) {
        		if(cmp(v[i],v[j])) swap(v[i],v[j]);
        	}
        }
        for(int i = 0; i < n; i++) cout<<v[i]<<" \n"[i == n-1];
    }
    return 0;
}





/*

*/