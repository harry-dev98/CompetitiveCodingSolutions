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
        vector<int> Arr(n);
        for(int& a: Arr)cin>>a;
        unordered_map<int, pair<int, int>>M;
        unordered_map<int, int> Processed;
        for(int itr=0; itr<n; itr++){
            if(M.find(Arr[itr]) == M.end()){
                M[Arr[itr]] = {itr+1, itr};
            } else {
                M[Arr[itr]].first = max(M[Arr[itr]].first, itr - M[Arr[itr]].second);
                M[Arr[itr]].second = itr;
            }
        }
        
        
        for(auto itr: M){
            itr.second.first = max(itr.second.first, n - itr.second.second);
            if(Processed.find(itr.second.first) == Processed.end()){
                Processed[itr.second.first] = itr.first;
            } else {
                Processed[itr.second.first] = min(itr.first, Processed[itr.second.first]);
            }
        }
        
        int ans = 1e9+7;
        for(int itr=0; itr<n; itr++){
            if(Processed.find(itr+1) != Processed.end()){
                ans = min(ans, Processed[itr+1]);
                cout<<ans<<" ";
            } else {
                if(ans == 1e9+7){
                    cout<<-1<<" ";
                } else {
                    cout<<ans<<" ";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}