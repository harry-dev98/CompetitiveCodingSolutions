#include<bits/stdc++.h>
using namespace std;
const long long _ = 1e9+7;
int main(){
    long long n, m;
    cin>>n>>m;
    vector<long long> Arr(n);
    for(long long& a: Arr)cin>>a;
    vector<vector<long long>> M(n, vector<long long>(m + 1, 0));
    long long prev = 0;
    long long ans = 0;
    for(long long i=0; i<n; i++){
        for(long long j=1; j<=m; j++){
            if(i == 0){
                if(Arr[i] == 0 || Arr[i] == j){
                    M[i][j] = 1;
                }
            } else {
                if(Arr[i] == 0 || Arr[i] == j){
                    if(j == 1){
                        M[i][j] = (M[prev][j] + M[prev][j+1])%_;
                    } else if(j == m){
                        M[i][j] = (M[prev][j-1] + M[prev][j])%_;
                    } else{
                        M[i][j] = ((M[prev][j-1] + M[prev][j])%_ + M[prev][j+1])%_;
                    }
                }
            }
        }
        prev = i;
    }

    for(long long i=1; i<=m; i++){
        ans = (ans + M[n-1][i])%_;
    }
    cout<<ans<<"\n";
    return 0;
}