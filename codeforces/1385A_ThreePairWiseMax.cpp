#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, x, y, z;
    cin>>t;
    while(t--){
        cin>>x>>y>>z;
        if(x == y && x == z){
            cout<<"YES\n";
            cout<<x<<" "<<x<<" "<<x<<"\n";
        }
        else if(x == y && x > z){
            cout<<"YES\n";
            cout<<x<<" "<<z<<" "<<z<<"\n";
        }
        else if(x == z && x > y){
            cout<<"YES\n";
            cout<<x<<" "<<y<<" "<<y<<"\n";
        }
        else if(y == z && y > x){
            cout<<"YES\n";
            cout<<z<<" "<<x<<" "<<x<<"\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}