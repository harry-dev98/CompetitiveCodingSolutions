#include<bits/stdc++.h>
using namespace std;

int main(){
    char c1, c2;
    int n;
    string s;
    cin>>s;
    c1 = s[0];
    c2 = s[1];
    bool c1_=false, c2_=false;
    cin>>n;
    while(n--){
        cin>>s;
        if(s[0] == c1 && s[1] == c2){
            c1_= true; c2_ = true;
        }
        if(s[0] == c2){
            c2_ = true;
        }
        if(s[1] == c1){
            c1_ = true;
        }
    }
    if(c1_ && c2_){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    cout<<"\n";
    return 0;
}