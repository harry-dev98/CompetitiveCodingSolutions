#include<bits/stdc++.h>
using namespace std;
const int m = 1e9+7;
int main(){
    int n, s;
    cin>>n>>s;
    int DP[s+1], val[n];
    for(int i=0; i<n; i++)cin>>val[i];
    DP[0] = 1;
    for(int i=1; i<=s; i++){
        DP[i] = 0;
        for(int j=0; j<n; j++){
            if(i - val[j]>=0){
                DP[i] = (DP[i] + DP[i-val[j]]) %m;
            }
        }
    }
    cout<<DP[s]<<"\n";
    return 0;
}