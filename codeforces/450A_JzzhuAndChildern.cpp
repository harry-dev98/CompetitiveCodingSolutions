#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, _;
    queue<pair<int, int>>Q;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>_;
        Q.push({i+1, _});
    }
    pair<int, int> ans;
    while(!Q.empty()){
        ans = Q.front();
        Q.pop();
        if(ans.second>m){
            Q.push({ans.first, ans.second-m});
        }
    }
    cout<<ans.first<<"\n";
    return 0;
}