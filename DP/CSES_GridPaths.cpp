#include<bits/stdc++.h>
using namespace std;
const int m = 1e9+7;
int main(){
    int n;
    cin>>n;
    string A[n];
    for(int i=0;i<n;i++)cin>>A[i];
    int noOfWays[n][n];
    memset(noOfWays, 0, sizeof(noOfWays));
    noOfWays[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] == '.'){
                if(i>0){
                    noOfWays[i][j] = noOfWays[i-1][j];
                }
                if(j>0){
                    noOfWays[i][j] += noOfWays[i][j-1];
                    noOfWays[i][j] %= m;
                }
            }
            else{
                noOfWays[i][j] = 0;
            }
        }
    }
    cout<<noOfWays[n-1][n-1]<<"\n";
    return 0;
}