#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t, n, r;
    cin>>t;
    while(t--){
        cin>>n>>r;
        vector<int> Arr(n);
        for(int& a: Arr)cin>>a;
        sort(Arr.begin(), Arr.end());
        cout<<(Arr[n-1]<=r||Arr[0]+Arr[1]<=r?"YES":"NO")<<"\n";
    }
    return 0;
}