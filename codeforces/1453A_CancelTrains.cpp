#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int>N(n),M(m);
        for(int& _: N)cin>>_;
        for(int& _: M)cin>>_;
        int ans = 0;
        for(int a: N){
            for(int b:M){
                if(a==b)ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}