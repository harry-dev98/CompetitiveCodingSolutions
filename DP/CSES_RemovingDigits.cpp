#include<bits/stdc++.h>
using namespace std;
int maxDigit(int n){
    int mx = 0, _;
    while(n){
        _ = n%10;
        if(_ > mx){
            mx = _;
        }
        n /= 10;
    }
    return mx;
}

int main(){
    int n;
    cin>>n;
    int DP[n+1];
    DP[0] = 0;
    for(int i=1; i<=9; i++){
        DP[i] = 1;
    }
    for(int i=10; i<=n; i++){
        DP[i] = DP[i-maxDigit(i)]+1;
    }
    cout<<DP[n]<<"\n";
    return 0;
}