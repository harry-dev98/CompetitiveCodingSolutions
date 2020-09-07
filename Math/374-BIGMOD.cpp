#include<bits/stdc++.h>
using namespace std;

long long binpowmod(long long x, long long y, long long m){
    x %= m;
    long long res = 1;
    while(y){
        if(y&1){
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
    long long B, P, M;
    string c;
    while(cin>>B){
        cin>>P>>M;
        getline(cin, c);
        cout<<binpowmod(B, P, M)<<"\n";
    }
    return 0;
}