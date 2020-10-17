#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t, n, s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        ll sum = 0;
        ll divisor = 1e18;
        ll threshold, tmp = n;
        while(n){
            if(sum < s){
                threshold=divisor*10;    
            }
            sum += n/divisor;
            n %= divisor;
            divisor /= 10;
        } 
        if(sum <= s){
            cout<<0;
        } else {
            cout<<threshold - (tmp%threshold);
        }
        cout<<"\n";
    }
    return 0;
}