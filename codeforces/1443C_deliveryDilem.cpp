#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int, int>> AB(n);
        for(auto &ab: AB)cin>>ab.first;
        for(auto &ab: AB)cin>>ab.second;
        sort(AB.begin(), AB.end(), comp);
        AB.push_back({0,0});
        int ans = AB[0].first, tmp;
        int self = 0;
        for(int i=0; i<n; i++){
            // cout<<i<<endl;
            if(AB[i].second >= AB[i].first){
                ans = AB[i].first + max(0, self - AB[i].first);
                // cout<<"here ok"<<ans<<endl;
                break;
            } else {
                self += AB[i].second;
                tmp = AB[i+1].first + max(0, self - AB[i+1].first);
                // cout<<"here "<<tmp<<endl;
            }
            if(tmp > ans){
                // cout<<"aaah here "<<tmp<<endl;
                break;
            }
            ans = tmp;
        }
        cout<<ans<<"\n";
    }
    return 0;
}