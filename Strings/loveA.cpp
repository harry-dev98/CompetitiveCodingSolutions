#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    n = (n+1)/2;
    int a = 0;
    for(auto ch:s){
        if(ch=='a'){
            a++;
        }
    }
    if(a>n){
        cout<<s.length();
    }
    else{
        cout<<2*a-1;
    }
    cout<<"\n";
    return 0;
}