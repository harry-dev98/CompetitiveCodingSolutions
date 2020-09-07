#include<iostream>

using namespace std;

const int MXN = 1e5+7;
int DP[MXN];
int A[MXN];

int solve(int n, int day, int bitmask){
    if(day == n)return 0;
    if(DP[bitmask] != -1)return DP[bitmask];
}

int main(){
    int n, d, m;
    cin>>n>>d>>m;
    for(int i=0; i<n; i++){
        cin>>A[i];
        DP[i] = -1;
    }
    cout<<solve(n, 0, 0)<<"\n";
    return 0;
}