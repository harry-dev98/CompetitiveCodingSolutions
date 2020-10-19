// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     vector<long long> Nums(n);
//     for(long long& num: Nums)cin>>num;
//     sort(Nums.begin(), Nums.end());
//     long long c = pow(Nums[n-1], 1/(n-1));
//     if(pow(c+1, n-1) - Nums[n-1] < Nums[n-1] -  pow(c, n-1)){
//         c = c+1;
//     }
//     long long ans = 0;
//     int p = 0;
//     for(long long num: Nums){
//         ans += abs(num - pow(c, p++)); 
//     }
//     cout<<ans<<"\n";
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int64_t INF = 1e17;
inline int64_t mul(int64_t a, int64_t b)
{
	return (INF / a > b ? a * b : INF);
}

inline int64_t add(int64_t a, int64_t b)
{
	return (a + b >= INF ? INF : a + b);
}

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(a.begin(), a.end());

	if (n <= 2) {
		cout << a[0] - 1 << endl;
	} else {
		int64_t ans = accumulate(a.begin(), a.end(), 0ll) - n;

		for (int x = 1; ; ++x) {
			int64_t curPow = 1, curCost = 0;
			for (int i = 0; i < n; ++i) {
				curCost = add(curCost, abs(a[i] - curPow));
				curPow = mul(curPow, x);
			}

			if (curPow == INF || curPow / x > ans + a[n - 1]) break;
			ans = min(ans, curCost);
		}

		cout << ans << endl;
	}
}