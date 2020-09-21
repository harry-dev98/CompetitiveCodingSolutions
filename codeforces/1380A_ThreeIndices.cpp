#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> P(n);
        for(int& _: P)cin>>_;
        bool ans = 0;
        for(int i=1; i<n-1; i++){
            if(P[i] > P[i-1]  && P[i] > P[i+1]){
                ans = true;
                cout<<"YES\n";
                cout<<i<<" "<<i+1<<" "<<i+2<<"\n";
                break;
            }
        }
        if(!ans){
            cout<<"NO\n";
        }
    }
    return 0;
}