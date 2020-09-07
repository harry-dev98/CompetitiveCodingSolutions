#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    char fletter = s[0];
    if('a'<=fletter && 'z'>=fletter){
        fletter = fletter - 'a' + 'A';
        s[0] = fletter;
    }
    cout<<s<<"\n";
    return 0;
}