#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
    SPEED;
    int t;
    cin>>t;
    while(t--){
        int n, k, x;
        cin>>n;
        int ARR[n];
        for(int i=0; i<n; i++){
            cin>>ARR[i];
        }
        sort(ARR, ARR+n);
        cin>>k;
        cout<<ARR[k-1]<<"\n";
    }
    return 0;
}