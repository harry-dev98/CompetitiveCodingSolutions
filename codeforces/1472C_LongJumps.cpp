#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> arr(n);
        for(int& a: arr)cin>>a;
        vector<int> maxScore(n+1, 0);
        for(int i=0; i<n; i++){
            if(i + arr[i] < n){
                maxScore[i+arr[i]] = max(maxScore[i+arr[i]], maxScore[i]+arr[i]);
            } else {
                maxScore[n] = max(maxScore[n], maxScore[i] + arr[i]);
            }
        }
        cout<<maxScore[n]<<"\n";
    }
    return 0;
}