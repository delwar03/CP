#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

bool cmp(char a, char b) {
    return (a == b && a == 'G');
}


//Will delete consequtive same elements:
void Unique() {

    vector<int> v = { 1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8 };

    auto it = unique(v.begin(),v.end());

    v.resize(distance(v.begin(),it));

    for(auto i : v) cout<<i<<" ";
}


//Will remove consequtive same elements when cmp is true:
void Unique_with_cmp() {

    string s = "You arre vvvisiting GGGGFGGGG";

    auto it = unique(s.begin(),s.end(),cmp);
    
    cout<<string(s.begin(),it);
}

 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    Unique(); cout<<'\n';
    Unique_with_cmp();
    return 0;
}





/*
12
1 1 3 3 3 10 1 3 3 7 7 8
*/