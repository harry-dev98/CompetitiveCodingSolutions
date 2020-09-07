#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;
    cin>>t;
    int sides = 0;
    while(t--){
        cin>>s;
        switch (s[0])
        {
        case 'T':
            sides+=4;
            break;
        
        case 'I':
            sides+=20;
            break;
        
        case 'C':
            sides+=6;
            break;
        
        case 'O':
            sides+=8;
            break;
        
        case 'D':
            sides+=12;
            break;
        
        default:
            break;
        }
    }
    cout<<sides<<"\n";
    return 0;
}