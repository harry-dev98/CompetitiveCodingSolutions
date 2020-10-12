#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, q, m;
    cin>>n;
    vector<int> Bars(n);
    for(int& _: Bars)cin>>_;
    sort(Bars.begin(), Bars.end());
    cin>>q;
    int l, h, mid, ans;
    while(q--){
        cin>>m;
        // cout<<(upper_bound(Bars.begin(), Bars.end(), m) - Bars.begin())<<"\n";
        if(m < Bars[0]){
            cout<<0<<"\n";
        }
        else{
            l = 0; h = n-1; ans = 0;
            while(l <= h){
                mid = l + (h - l)/2;
                if(Bars[mid] <= m){
                    l = mid+1;
                } 
                else{
                    h = mid - 1;
                }
            }
            cout<<l<<"\n";
        }
    }
    return 0;
}