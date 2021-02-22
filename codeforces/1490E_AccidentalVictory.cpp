#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<ll, ll>> Arr(n);
        vector<ll> pref;
        ll itr = 0;
        for(auto& a: Arr){
            cin>>a.first;
            a.second = itr++;
        }
        sort(Arr.begin(), Arr.end());
        for(auto a: Arr){
            if(pref.empty()){
                pref.push_back(a.first);
            } else {
                pref.push_back(pref.back() + a.first);
            }
        }
        ll low = 0, high = n, mid;
        while(low < high){
            mid = low + (high - low)/2;
            bool f = true;
            for(ll i=mid; i<high; i++){
                if(i!=n-1 && pref[i]<Arr[i+1].first){
                    f = false;
                    break;
                }
            }
            if(f){
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        set<ll> ans;
        for(ll i=low; i<n; i++){
            ans.insert(Arr[i].second);
        }
        cout<<ans.size()<<"\n";
        for(ll a: ans){
            cout<<a+1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}