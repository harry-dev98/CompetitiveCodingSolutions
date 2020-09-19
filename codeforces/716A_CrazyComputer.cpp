#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, c;
    cin>>n>>c;
    vector<int> Sec(n);
    for(int& _: Sec)cin>>_;
    int ans = 1;
    for(int i=1; i<n; i++){
        if(Sec[i] - Sec[i-1]<=c)ans++;
        else{ans = 1;}
    }
    
    cout<<ans<<"\n";
    return 0;
}