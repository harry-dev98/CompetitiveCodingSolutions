#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
int main(){
    int n;
    cin>>n;
    int DP[n+1];
    DP[0] = 1;
    for(int i=1; i<=n; i++){
        DP[i] = 0;
        for(int j=1; j<=6; j++){
            if(i>=j){
                DP[i] = (DP[i]%m + DP[i-j]%m) %m;
            }
        }
    }
    cout<<DP[n]<<"\n";
    return 0;
}