#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    if(n==1){
        cout<<"YES\n";
        return 0;
    }
    string r = s;
    reverse(r.begin(), r.end());
    if(r==s){
        if((r.length())%2)
        cout<<"YES\n";
        else 
        cout<<"NO\n";
        return 0;
    }
    int x=0;
    for(int i=0; i<n/2; i++){
        if(s[i] != s[n-1-i]){
            x++;
        }    
        if(x>1){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}