#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin>>n;
    vector<ll> Worms(n);
    for(ll& _: Worms)cin>>_;
    ll runninsum = 0;
    for(ll& _: Worms){
        runninsum += _;
        _ = runninsum;
    }
    cin>>m;
    while(m--){
        cin>>q;
        int low=0, hi=n-1, mid;
        while(low <= hi){
            mid = low + (hi - low)/2;
            if(Worms[mid] < q){
                low = mid + 1;
            }
            else hi = mid - 1;
        }
        cout<<low+1<<"\n";
    }
    return 0;
}