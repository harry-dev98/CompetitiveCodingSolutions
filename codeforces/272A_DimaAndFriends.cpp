#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, _;
    int fing = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>_;
        fing+=_;
    }
    n+=1;
    int ans = 0;
    for(int i=1; i<=5; i++){
        if((fing+i)%n!=1){
            ans ++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}