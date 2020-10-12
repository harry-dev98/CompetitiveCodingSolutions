#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    ll n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        ll _ = k / (n);
        ll __ = k % (n-1);
        _ = n * _;
        cout<<_+__<<"\n";
    }
    return 0;
}