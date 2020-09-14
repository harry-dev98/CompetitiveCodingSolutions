#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, _;
    cin>>n;
    vector<int>A(n, 0);
    for(int j=0; j<n; j++){
        for(int i=0; i<3; i++){
            cin>>_;
            A[j]+=_;
        }
    }
    int ans = 0;
    for(int a: A){
        if(a>=2)ans++;
    }
    cout<<ans<<"\n";
    return 0;
}