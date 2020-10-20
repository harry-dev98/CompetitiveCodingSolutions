#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> Arr(n);
    for(long long& a: Arr)cin>>a;
    sort(Arr.begin(), Arr.end());
    long long ans = 0;
    for(long long i=0; i<n; i++){
        ans = max(Arr[i] * (n-i), ans);
    }
    cout<<ans<<"\n";
}