#include<bits/stdc++.h>
using namespace std;
long long binpow_mod(long long a, long long b, long long m){
    a %= m;
    long long ans = 1;
    while(b){
        if(b&1){
            ans*=a;
            ans%=m;
        }
        a*=a;
        a%=m;
        b>>=1;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    long long a,b;
    while(t--){
        cin>>a>>b;
        cout<<binpow_mod(a, b, 10)<<'\n';
    }
    return 0;
}