#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t, a, b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a%b){
            if(a>b){
                swap(a, b);
            }
            cout<<(b+a-1)/a<<"\n";
        } else {
            cout<<1<<"\n";
        }
    }
    return 0;
}