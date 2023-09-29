#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x; cin>>x;
	int arr[10] = {2, 7, 12, 14, 18, 21, 25, 26, 32, 65};

	//lower_bound returns iterator to the first 
	//element which is not less than val 
	auto l = lower_bound(arr,arr+10,x);


	//upper bound returns iterator to the first  
	//element which is greater(strictly) than val
	auto u = upper_bound(arr,arr+10,x);

	cout<<"Lower_bound of "<<x<<" is present in index -> "<<l-arr<<endl;
	cout<<"Upper_bound of "<<x<<" is present in index -> "<<u-arr<<endl;
	return 0;
}

//TC -> O(nlogn)