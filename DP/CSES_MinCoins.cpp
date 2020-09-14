#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, s;
    cin>>n>>s;
    vector<int> DP(s+1, 1e9+7), val(n);
    DP[0] = 0;
    for(int i=0; i<n; i++)cin>>val[i];
    for(int i=0; i<n; i++){
        for(int j=1; j<=s; j++){
            if(j-val[i]>=0){
                DP[j] = min(DP[j], DP[j-val[i]]+1);
            }
        }
    }
    cout<<(DP[s]==1e9+7?-1:DP[s])<<"\n";
    return 0;
}