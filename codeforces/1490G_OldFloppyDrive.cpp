#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll t, n, m, S, maxPrefS;
    cin>>t;
    while(t--){
        cin>>n>>m;
        S = 0;
        vector<ll>X(m), A, Ind;
        ll ip;
        for(ll i=0; i<n; i++){
            cin>>ip;
            S += ip;
            if(A.empty() || S > A.back()){
                A.push_back(S);
                Ind.push_back(i);
            }
        }
        maxPrefS = A.back();
        for(ll& _: X)cin>>_;
        ll time, fullRound;
        for(ll x: X){
            if(x > maxPrefS && S <= 0){
                cout<<-1<<" ";
            } else {
                fullRound = 0;
                if(x > maxPrefS){
                    fullRound = (x - maxPrefS + S - 1) / S; 
                }
                time = fullRound * n;
                x = x - fullRound * S;
                ll lb = lower_bound(A.begin(), A.end(), x) - A.begin();
                cout<<time + Ind[lb] <<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}