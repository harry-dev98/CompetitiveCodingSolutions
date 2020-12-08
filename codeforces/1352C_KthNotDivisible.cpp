#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    long long n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n>k)cout<<k<<"\n";
        else{
            long long ans, low = k, high = 2*k+1, mid;
            while(low < high){
                mid = (low + high)/2;
                long long _ = mid / n;
                if(mid - _ > k){
                    high = mid;
                } else if( mid - _ < k){
                    low = mid;
                } else {
                    ans = mid%n==0?mid-1:mid;
                    break;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}