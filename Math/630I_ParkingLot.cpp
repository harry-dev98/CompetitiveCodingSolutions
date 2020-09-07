#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b){
    long long res = 1;
    while(b){
        if(b&1){
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n;
    cin>>n;
    cout<<2*3*binpow(4, n-2) + (n-3)*9*binpow(4, n-3)<<"\n";
    return 0;
}