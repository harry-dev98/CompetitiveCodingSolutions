#include<bits/stdc++.h>
using namespace std;

#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


int main(){
    SPEED;
    string s1, s2;
    cin>>s1>>s2;
    int n1 = s1.length(), n2 = s2.length();
    int sind1 = 0, sind2 = 0;
    while(s1[sind1]=='0'){
        sind1++;
    }
    while(s2[sind2]=='0'){
        sind2++;
    }
    int n1_ = n1-sind1;
    int n2_ = n2-sind2;
    if(n1_ == n2_){
        if(s1.substr(sind1, n1_) == s2.substr(sind2, n2_)){
            cout<<"=";
        }
        else if(s1.substr(sind1, n1_) < s2.substr(sind2, n2_)){
            cout<<"<";
        }
        else{
            cout<<">";
        }
    }
    else{
        if(n1_>n2_){
            cout<<">";
        }
        else{
            cout<<"<";
        }
    }
    cout<<"\n";
    return 0;
}