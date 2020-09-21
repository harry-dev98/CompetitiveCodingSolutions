#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, a, k;
    cin>>t;
    while(t--){
        cin>>a>>k;
        if(a<k){
            cout<<k-a<<"\n";
        }
        else{
            cout<<(a%2 == k%2?0:1)<<"\n";
        }
    }
    return 0;
}