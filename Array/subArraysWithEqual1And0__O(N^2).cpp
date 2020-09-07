#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n+1];
        for(int i=1; i<=n; i++){
            cin>>A[i];
        }
        pair<int, int> dp[n+1];
        int j;
        for(int i=1; i<=n; i++){
            dp[i] = (A[i]==1)?make_pair(1,0):make_pair(0,1);
        }
        long long ans = 0;
        for(int k=2; k<=n; k++){
            for(int i=1; i<=n-k+1; i++){
                j = i + k -1;   
                // cout<<i<<" "<<dp[i].first<<dp[i].second<<endl;
                dp[i] = A[j]==1?make_pair(dp[i].first+1, dp[i].second):make_pair(dp[i].first, dp[i].second+1);
                // cout<<j<<" "<<dp[i].first<<dp[i].second<<endl;
                ans = dp[i].first == dp[i].second? ans+1: ans;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
