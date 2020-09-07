#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007


// binary exponentiation
ll binpow(ll a, ll n) {
	if(n == 0)
		return 1;
	if(n == 1)
		return a%M;
	ll r = binpow(a, n/2);
	if(n % 2 == 0) {
		return (r%M * r%M)%M;
	}
	else 
		return (r%M * r%M * a%M)%M;
}
// long long M = 1000000007;
// unordered_map<long long, long long> Map;
// long long binpow(long long a, long long b){
//     a %= M;
//     long long res = 1;
//     while(b){
//         if(Map.find(b) != Map.end()){
//             return Map[b];
//         }
//         if(b&1){
//             res *= a;
//             res %= M;
//         }
//         a *= a;
//         a %= M;
//         b >>= 1;
//     }
//     return res;
// }
/*
    say we have some k st k * n/k = n;
    we need to maximize k^n/k..
    using differentiation (Minima Maxima)
    we conclude having k = e i.e k = 3(aprox.)
    will give us the maximum..

*/

// int main(){
//     int t, n; 
//     cin>>t;
//     while(t--){
//         cin>>n;
//         if(n<3){
//             cout<<n<<"\n";
//             continue;
//         }
//         long long ans = (n%3==0)?binpow(3,n/3):(n%3==1)?4*binpow(3, (n/3)-1):n%3*binpow(3,n/3);
//         cout<<ans%M<<"\n";
//     }
//     return 0;
// }


int main () {
	ll t, n;
	cin >> t;
	while(t--) {
		ll ans, n1;
		cin >> n;
		if(n < 3) {
			cout << n << endl;
			continue;
		}
		if(n%3 == 1) {
			n1 = (n - 4) / 3;
			ans = 4*binpow(3, n1);
		}
		else if(n%3 == 2){
			n1 = (n - 2) / 3;
			ans = 2*binpow(3, n1);
		}
		else 
			ans = binpow(3, n/3);
		ans %= M;
		cout << ans << endl;
	}
	
}