#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, ans = 0;
    cin>>t;
    int GrupSz[5] = { 0, 0, 0, 0, 0 };
    while(t--){
        cin>>n;
        GrupSz[n]++;
    }
    ans += GrupSz[4];
    ans += GrupSz[2]/2;
    GrupSz[2] %= 2;
    int _ = min(GrupSz[1], GrupSz[3]); 
    ans += _;
    GrupSz[1] -= _;
    GrupSz[3] -= _;
    if(GrupSz[1] == 0){
        ans += GrupSz[3];
        ans += GrupSz[2];
    }
    else{
        if(GrupSz[2] == 1){
            ans += 1 + max(0, (GrupSz[1]-2+3)/4);        
        }
        else{
            ans += (GrupSz[1] + 3)/4;
        }
    }
    cout<<ans<<"\n";
    return 0;
}