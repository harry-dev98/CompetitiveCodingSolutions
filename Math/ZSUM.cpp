#include<bits/stdc++.h>
using namespace std;
const long long M = 1e7+7;

long long binpowmod(long long n, long long k){
    n %= M;
    long long res = 1;
    while(k){
        if(k&1){
            res = (res*n) %M;
        }
        n = (n*n) %M;
        k >>= 1;
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, k;
    cin>>n>>k;
    while(n!=0 && k != 0){
        long long S1 = binpowmod(n, min(n, k)) ;
        long long S2 = (S1 * binpowmod(n, abs(n-k))) % M;
        long long S = (S1 + S2)%M;
        n--;
        long long P1 = binpowmod(n, min(n, k));
        long long P2 = (P1 * binpowmod(n, abs(n-k))) %M;
        long long P = (P1 + P2)%M;
        P = 2LL *P %M;
        cout<<(S%M+P%M)%M<<"\n";
        cin>>n>>k;
    }
    return 0;
}