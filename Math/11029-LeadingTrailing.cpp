#include<bits/stdc++.h>
using namespace std;

long long binpowmod(long long n, long long k, long long m){
    n %= m;
    long long res = 1;
    while(k){
        if(k&1){
            res = (res*n)%m;
        }
        n = (n*n)%m;
        k >>= 1;
    }
    return res;
}

int main(){
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int trailing = binpowmod(n, k, 1000);
        long double logbase10 = k*log10(n);
        long double reqlogbase10 = logbase10 - floor(logbase10);
        long double req = pow(10, reqlogbase10+2);
        int leading = floor(req);
        // cout<<leading<<"..."<<trailing<<"\n";
        printf("%d...%03d\n", leading, trailing);
    }
    return 0;
}