#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int prod(int x, int y) {
	return x*y;
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sum = 1;
	vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout<<"\n\nResult using Simple default Accumulate function : ";
	cout<<accumulate(v.begin(),v.end(),sum)<<endl; //56

	cout<<"\n\nResult using Accumulate with user defined function : ";
	cout<<accumulate(v.begin(),v.end(),sum,prod)<<endl; //10! = 3628800

	cout<<"\n\nResult using Accumulate with pre defined function : ";
	cout<<accumulate(v.begin(),v.end(),sum,std::minus<int>())<<endl; //-54

	return 0;
}