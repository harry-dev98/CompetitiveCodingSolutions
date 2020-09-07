#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, ans="";
    cin>>s;
    int n = s.length();
    int j = (n-1)/2;
    int i = j;
    ans += s[i];
    while(i>0 && j<n-1){
        i--; j++;
        ans += s[j];
        ans += s[i];
    }
    if(j!=n-1){
        ans+=s[n-1];
    }
    cout<<ans<<"\n";
    return 0;
}