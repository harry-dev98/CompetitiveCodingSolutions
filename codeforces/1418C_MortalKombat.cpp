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
        vector<int> Bosses(n);
        for(int& b: Bosses)cin>>b;
        vector<int> SkipPoint(n+3, 2e5+7);
        SkipPoint[0] = Bosses[0] == 1? 1: 0;
        // SkipPoint[1] = SkipPoint[0];
        for(int itr=0; itr<n; itr++){
            SkipPoint[itr+1] = min(SkipPoint[itr+1], SkipPoint[itr]+(itr<n-1?Bosses[itr+1]:0));
            SkipPoint[itr+2] = min(SkipPoint[itr+2], SkipPoint[itr]+(itr<n-2?Bosses[itr+2]:0));
            SkipPoint[itr+3] = min(SkipPoint[itr+3], SkipPoint[itr]+(itr<n-3?Bosses[itr+3]:0));
        }
        cout<<SkipPoint[n]<<"\n";
    }
    return 0;
}