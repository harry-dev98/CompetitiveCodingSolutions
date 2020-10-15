#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll>Arr(n);
    for(ll& a: Arr)cin>>a;
    unordered_set<ll> Set;
    ll prefixSum = 0;
    int ans = 0;
    for(ll a: Arr){
        prefixSum += a;
        if(Set.find(prefixSum) == Set.end() && prefixSum != 0){
            Set.insert(prefixSum);
        } else {
            ans++;
            Set.clear();
            prefixSum = a;
            Set.insert(a);
        }
    }
    cout<<ans<<"\n";
    return 0;
}