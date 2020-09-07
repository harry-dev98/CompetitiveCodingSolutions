#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;
    cin>>n>>s;
    int one=0, zero=0;
    for(auto ch:s){
        if(ch=='z'){
            zero++;
        }
        else if(ch=='n'){
            one++;
        }
    }
    while(one--){
        cout<<1<<" ";
    }
    while(zero--){
        cout<<0<<" ";
    }
    cout<<"\n";
    return 0;
}