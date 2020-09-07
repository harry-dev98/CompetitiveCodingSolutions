#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define M 1000000000000009
#define P 31


int main(){
    string str, alphaType;
    int k;
    cin>>str>>alphaType>>k;
    int n = str.length();
    vector<unsigned long long> P_pow(n);
    vector<unsigned long long> Hash(n+1);
    vector<int> BadL(n+1);
    P_pow[0] = 1;
    for(int i=1; i<n; i++){
        P_pow[i] = (P_pow[i-1] * P)%M;
    }
    Hash[0] = 0;
    BadL[0] = 0;
    for(int i = 0; i < n; i++){
        Hash[i+1] = (Hash[i] + (str[i] - 'a' + 1)*P_pow[i])%M;    
        BadL[i+1] = ((alphaType[str[i]-'a']=='1')?0:1) + BadL[i];
    }
    set<long long> Unique;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            unsigned long long curHash = (Hash[j+i] + M - Hash[j])%M;
            curHash = (curHash * P_pow[n-j-1])%M;
            if((BadL[j+i]-BadL[j]) <= k){
                Unique.insert(curHash);
            }
        }
    }
    cout<<Unique.size()<<"\n";
    return 0;
}