#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int& h: heights)cin>>h;
    int mindif = abs(heights[0] - heights[n-1]);
    pair<int, int> ans = {1, n};
    for(int i=1; i<n; i++){
        if(mindif > abs(heights[i-1] - heights[i])){
            ans = {i, i+1};
            mindif = abs(heights[i-1] - heights[i]);
        }
    }
    cout<<ans.first<<" "<<ans.second<<"\n";
    return 0;
}