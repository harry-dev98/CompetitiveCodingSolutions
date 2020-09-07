#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;
    reverse(s1.begin(), s1.end());
    if(s1 != s2){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
    return 0;
}