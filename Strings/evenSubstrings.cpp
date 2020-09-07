#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, ans=0;
    string s;
    cin>>t>>s;
    for(int i=0; i<t; i++){
        n = s[i] - '0';
        if(n%2==0){
            ans+= i+1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}