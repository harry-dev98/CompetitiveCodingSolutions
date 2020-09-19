#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int m = 1e9+7;
ll binpow(ll a, ll b){
    a %= m;
    ll res = 1;
    while(b){
        if(b&1){
            res = (res * a) % m;
        }
        a = (a * a)% m;
        b >>= 1;
    }
    return res;
}
int main(){
    ll n;
    cin>>n;
    cout<<((binpow(10LL, n) - (2 * binpow(9LL, n))%m + binpow(8LL, n)) + m)%m<<"\n";
    return 0;
}