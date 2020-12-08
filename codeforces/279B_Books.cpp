#include<bits/stdc++.h>
using namespace std;

bool isValid(int book, vector<long long> B, int t){
    // cout<<book<<" ";
    int sz = B.size();
    bool ans = false;
    long long time = 0;
    for(int i=0; i<sz-book+1; i++){
        if(i == 0){
            time = B[book-1];
        } else {
            time = B[book + i - 1] - B[i-1];
        }
        // cout<<"- "<<time<<" ";
        if(time <= t){
            ans = true;
        }
    }
    // cout<<ans<<"\n";
    return ans;
}

int main(){
    int n, t;
    cin>>n>>t;
    vector<long long> B(n);
    for(long long& b: B)cin>>b;
    for(int i=1; i<n; i++){
        B[i] += B[i-1];
    }
    int low = 0, high = n, mid, ans = 0;
    while(low <= high){
        mid = low + (high-low)/2;
        if(isValid(mid, B, t)){
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}