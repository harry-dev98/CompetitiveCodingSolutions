#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;
    cin>>t>>s;
    int zeros = 0, ones = 0;
    for(auto ch:s){
        if(ch=='0'){
            zeros++;
        }
        else{
            ones++;
        }
    }
    if(ones!=zeros){
        cout<<1<<"\n"<<s<<"\n";
    }
    else{
        cout<<2<<"\n"<<s.substr(0,t-1)<<" "<<s[t-1]<<"\n";
    }
    return 0;
}