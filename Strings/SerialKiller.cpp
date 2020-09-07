#include<bits/stdc++.h>
using namespace std;

#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main(){
    SPEED;
    string s1,s2, s3, s4;
    int t;
    cin>>s1>>s2;
    cin>>t;
    cout<<s1<<" "<<s2<<"\n";
    while(t--){
        cin>>s3>>s4;
        if(s1==s3){
            s1 = s4;
        }
        else{
            s2 = s4;
        }
        cout<<s1<<" "<<s2<<"\n";
    }
    return 0;
}