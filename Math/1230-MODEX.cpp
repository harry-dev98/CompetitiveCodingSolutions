#include<bits/stdc++.h>
using namespace std;

long long binpowmod(long long x, long long y, long long m){
    x %= m;
    long long res = 1;
    while(y){
        if(y & 1){
            res *= x;
            res %= m;
        }
        x *= x;
        x %= m;
        y >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t, x, y, n, c;
    cin>>t;
    while(t--){
        cin>>x>>y>>n;
        cout<<binpowmod(x, y, n)<<"\n";
    }
    cin>>c;
    return c;
}