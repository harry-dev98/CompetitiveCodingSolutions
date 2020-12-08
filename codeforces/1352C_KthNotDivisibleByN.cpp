#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*
wornggggggly attempted,  refer 1352C_KthNotDivisible.cpp
 for binary search solution...
*/
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