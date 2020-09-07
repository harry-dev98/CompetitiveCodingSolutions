#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0)
#define M 1000000009
#define P 31

long long binpow_mod(long long a, long long b){
    a %= M;
    long long ans = 1;
    while(b>0){
        if(b&1){
            ans = ans * a % M;
        }
        a = a * a % M;
        b >>= 1;
    }
    return ans;
}


int main(){
    SPEED;
    int n, m;
    while(cin>>n){
        string s1, s2;
        cin>>s1>>s2;
        m = s2.size();
        vector<long long> P_pow(m);
        vector<long long> P_invpow(m);
        vector<long long> Hash(m+1, 0);
        P_pow[0] = 1;
        P_invpow[0] = 1;
        for(int i=1; i<m; i++){
            P_pow[i] = (P * P_pow[i-1])%M;
            P_invpow[i] = binpow_mod(P_pow[i], M-2);
        }
        long long Hash_s1 = 0;
        for(int i=0; i<n; i++){
            Hash_s1 = (Hash_s1 + (s1[i]-'a'+1)*P_pow[i])%M;
        }
        for(int i=0; i<m; i++){
            Hash[i+1] = (Hash[i] + (s2[i]-'a'+1)*P_pow[i])%M;
        }
        vector<int> Ans;
        for(int i=0; i<=m-n; i++){
            long long curHash = ((Hash[i+n]+M - Hash[i])%M * P_invpow[i])%M;
            if(curHash == Hash_s1){
                Ans.push_back(i);
            }
        }
        if(Ans.empty()){
            cout<<"\n";
        }
        else{
            for(auto itr:Ans){
                cout<<itr<<"\n";
            }
        }
    }
    return 0;
}