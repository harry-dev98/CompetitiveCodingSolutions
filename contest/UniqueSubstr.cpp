#include<bits/stdc++.h>
using namespace std;

#define P 31
#define M 1000000009

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

vector<long long> P_pow(101, 0);

int main(){
    P_pow[0] = 1;
    for(int i=1; i<101; i++){
        P_pow[i] = (P_pow[i-1]*P)%M;
    }
    int t, n;
    cin>>t;
    string str;
    vector<long long> Hash(t);
    for(int i=0; i<t; i++){
        cin>>str;
        n = str.length();
        vector<long long> hash(n+1, 0);
        for(int i=0; i<n; i++){
            hash[i+1] = (hash[i] + (str[i]-'a'+1)*P_pow[i])%M;
        }
        Hash[i] = hash[n];
    }
    cin>>n;
    cin>>str;

    vector<long long> hash(n+1, 0);
    for(int i=0; i<n; i++){
        hash[i+1] = (hash[i] + (str[i]-'a'+1)*P_pow[i])%M;
    }
    set<long long> UniqueHash;

    for(int i=1; i<=n; i++){
        for(int j=0; j<= n-i; j++){
            long long curHash_ij = (hash[i+j]+M - hash[j])%M;
            curHash_ij *= binpow_mod(P_pow[i], M-2, M);
            curHash_ij %= M;
            UniqueHash.insert(curHash_ij); 
        }
    } 
    int ans = 0;   
    for(auto itr:Hash){
        if(UniqueHash.find(itr) != UniqueHash.end()){
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}