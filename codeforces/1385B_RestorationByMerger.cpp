#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> A(2*n);
        for(int& _: A)cin>>_;
        vector<bool> Check(n, 0);
        vector<int> ans;
        for(int _: A){
            if(!Check[_]){
                Check[_] = 1;
                ans.push_back(_);
            }
        }
        for(int _: ans)cout<<_<<" ";
        cout<<"\n";
    }
    return 0;
}