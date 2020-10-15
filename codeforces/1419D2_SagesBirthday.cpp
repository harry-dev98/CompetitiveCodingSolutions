#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> spherePrice(n);
    for(int& sp: spherePrice)cin>>sp;
    sort(spherePrice.begin(), spherePrice.end());
    int low, high, mid, ans = 0;
    low = 0; high = n-1;
    while(low <= high){
        mid = low + (high - low)/2;
        bool flag = true;
        if(2*mid+1>n)flag = false;
        else {
            int eleAfter = 0, eleBefore = 0;
            for(int i=mid; i<n; i++){
                if(spherePrice[i] == spherePrice[mid-1])eleAfter++;
                else break;
            }
            for(int i=mid-1; i>=0; i--){
                if(spherePrice[i] == spherePrice[mid-1])eleBefore++;
                else break;
            }
            if(n - mid - eleAfter < eleBefore+1)flag = false;
        }
        // cout<<high<<" "<<low<<" "<<mid<<" "<<flag<<"\n";
        if(flag){
            ans = max(ans, mid);
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<ans<<"\n";
    int cheapSphere = 2*ans + 1 - n;
    for(int i=ans; i<n; i++){
        cout<<spherePrice[i]<<" ";
        if(cheapSphere < ans && cheapSphere >= 0) cout<<spherePrice[cheapSphere]<<" ";
        cheapSphere++;
    }
    cout<<"\n";
    return 0;
}