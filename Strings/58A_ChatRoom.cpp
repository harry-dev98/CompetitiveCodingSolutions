#include<bits/stdc++.h>
using namespace std;

int main(){
    string test, pat = "hello";
    int ptr = 0;
    cin>>test;
    for(auto c:test){
        if(c == pat[ptr]){
            ptr++;
        }
    }
    if(ptr==5){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}