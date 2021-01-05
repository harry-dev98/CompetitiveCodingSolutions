#include<bits/stdc++.h>
using namespace std;
bool comp(long long a, long long b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<long long> arr(n);
        for(long long& a: arr)cin>>a;
        sort(arr.begin(), arr.end(), comp);
        long long ans = 0;
        for(long long i=0; i<n; i++){
            if(i%2==0){
                if(arr[i]%2==0)ans+=arr[i];
            } else {
                if(arr[i]%2==1)ans-=arr[i];
            }
        }
        string res;
        if(ans == 0)res = "Tie";
        else if(ans > 0) res = "Alice";
        else res = "Bob";
        cout<<res<<"\n";
    }
    return 0;
}