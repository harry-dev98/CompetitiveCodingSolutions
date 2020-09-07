#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        if(n==2){
            if(s[0] < s[1]){
                cout<<"YES\n2\n"<<s[0]<<" "<<s[1]<<"\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            cout<<"YES\n2\n"<<s[0]<<" "<<s.substr(1, n-1)<<"\n";
        }
    }
    return 0;
}