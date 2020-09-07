#include<iostream>
using namespace std;

int main(){
    int t, a, b, c, a_=0, b_=0, c_=0;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        a_+=a;
        b_+=b;
        c_+=c;
    }
    if(a_==0 && b_==0 && c_==0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}