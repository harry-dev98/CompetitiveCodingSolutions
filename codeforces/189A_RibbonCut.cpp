#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, a[3];
    cin>>n>>a[0]>>a[1]>>a[2];
    vector<long long> MaxCuts(4007, 0);
    MaxCuts[a[0]] = 1;
    MaxCuts[a[1]] = 1;
    MaxCuts[a[2]] = 1;
    long long sz = 1;
    while(sz<=n){
        if(MaxCuts[sz]){
           for(int i=0; i<3; i++){
               if(sz+a[i] <= n){
                   MaxCuts[sz+a[i]] = max(MaxCuts[sz+a[i]], MaxCuts[sz] + 1);
               }
           }     
        }
        sz++;
    }
    cout<<MaxCuts[n]<<"\n";
    return 0;
}