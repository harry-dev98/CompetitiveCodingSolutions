#include<bits/stdc++.h>
using namespace std;

/*
    Since we know that the module operator doesn't interfere with multiplications 
    (a⋅b≡(amodm)⋅(bmodm)(modm)), we can directly use the same code, and just 
    replace every multiplication with a modular multiplication
*/
long long binpow_mod(long long a, long long b, long long m){
    a %= m;
    long long ans = 1;
    while(b){
        if(b&1){
            ans = (ans*a) % m;
        }
        a = (a*a) % m;
        b >>= 1;
    }
    return ans;
}


long long binpow_rec(long long a, long long b){
    if(b==0){
        return 1;
    }
    long long ans = binpow_rec(a, b/2);
    return ans * ans * ((b%2==0)?1:a);
}

long long binpow(long long a, long long b){
    long long ans = 1;
    while(b){
        if(b&1){
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main(){
    long long a = 6, b = 2;
    cout<<binpow_rec(a,b)<<", "<<binpow(a, b)<<", "<<binpow_mod(a, b, 1000000009)%10<<endl;

    return 0;
}