#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    int a=0, d=0;
    cin>>s;
    for(auto ch:s){
        if(ch=='A'){
            a++;
        }
        else{
            d++;
        }
    }
    string ans = (a>d)?"Anton":(a==d)?"Friendship":"Danik";
    cout<<ans<<"\n";
    return 0;
}