#include<bits/stdc++.h>
using namespace std;

#define N 1000001
bool seive[N];
long DP[N];
long getVictoryNo(int n){
    if(DP[n] != 0){
        return DP[n];
    }
    if(n<2){
        return 0;
    }
    DP[n] = getVictoryNo(n-1) + ((seive[n]==true)?n:0);
    return DP[n];
}

int main(){
    memset(seive, 1, sizeof(seive));
    memset(DP, 0, sizeof(DP));
    for(int i=2; i<sqrt(N); i++){
        if(seive[i]==true){
            for(int j = i*i; j<N; j+=i){
                seive[j] = false;
            }
        }
    }
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<getVictoryNo(n)<<"\n";
    }
    return 0;
}