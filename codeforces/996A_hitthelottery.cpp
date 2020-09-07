#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int Bills[] = {1, 5, 10, 20, 100};
    int ans = 0;
    for(int i=4; i>=0; i--){
        while(n>=Bills[i]){
            ans++;
            n-=Bills[i];
        }
    }
    cout<<ans<<"\n";
    // int DP[n+1];
    // memset(DP, 0, sizeof(DP));
    // for(int i=0; i<5; i++){
    //     for(int j=1; j<n+1; j++){
    //         if(i==0){
    //             DP[j] = j;
    //         }
    //         else{
    //             DP[j] = (j>=Bills[i])?DP[j-Bills[i]]+1:DP[j];
    //         }
    //     }
    // }
    // cout<<DP[n]<<"\n";
    return 0;
}