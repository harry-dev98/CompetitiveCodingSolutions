#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, l;
    cin>>n>>l;
    vector<long long>Loc(n);
    for(long long& _: Loc)cin>>_;
    sort(Loc.begin(), Loc.end());
    double d = Loc[0] - 0;
    d = max(d, (double)(l - Loc[n-1]));
    for(int i=0; i<n-1; i++){
        d = max(d, ((double)(Loc[i+1]-Loc[i]))/2);
    }
    cout<<fixed<<setprecision(9)<<d<<"\n";
    return 0;
}