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
        int i = 4*n-2;
        while(n--){
            cout<<i<<" ";
            i -= 2;
        }
        cout<<"\n";
    }
    return 0;
}