#include<bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& steps, int step=1, int pos=1){
    if(pos > n)return;
    if(pos < 0)return;
    steps[pos-1] = min(steps[pos-1], steps[pos]+1);
    solve(n, steps, step+1, pos-1);
    steps[pos+step] = min(steps[pos+step], steps[pos]+1);
    solve(n, steps, step+1, pos+step);
}

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>steps(n+1, 1e9);
        steps[0] = 0;
        steps[1] = 1;
        solve(n, steps);
        cout<<steps[n]<<"\n";
    }
    return 0;
}