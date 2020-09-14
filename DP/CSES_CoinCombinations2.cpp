#include<bits/stdc++.h>
using namespace std;
const int m = 1e9+7;
int main(){
    int n, s;
    cin>>n>>s;
    vector<int> val(n), DP(s+1, 0);
    DP[0] = 1;
    for(int& v: val)cin>>v;
    for(int i=0; i<n; i++){
        for(int j=0; j<=s; j++){
            if(j >= val[i]){
                DP[j] = DP[j-val[i]]+DP[j];
                DP[j] %= m;
            }
        }
    }
    cout<<DP[s]<<"\n";
    return 0;
}