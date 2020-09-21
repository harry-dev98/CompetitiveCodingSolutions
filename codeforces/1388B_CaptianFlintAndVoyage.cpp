#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n; 
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n-(n+3)/4; i++){
            cout<<9;
        }
        for(int i=0; i<(n+3)/4; i++){
            cout<<8;
        }
        cout<<"\n";
    }
    return 0;
}