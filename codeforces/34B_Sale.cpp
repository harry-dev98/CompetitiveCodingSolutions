#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>Cost(n);
    for(int& c: Cost)cin>>c;
    int ans = 0;
    int mn = 1e9+7;
    sort(Cost.begin(), Cost.end());
    for(int c: Cost){
        if(c<0){
            ans -= c;
            m--;
            if(m==0)break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}