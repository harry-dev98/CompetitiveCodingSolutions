#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int lind, n = s.length();
    for(lind=0; lind<n; lind++){
        if(s[lind]=='.'){
            break;
        }
    }
    if(s[lind-1] == '9'){
        cout<<"GOTO Vasilisa.";
    }
    else{
        if(s[lind+1]-'0' < 5){
            cout<<s.substr(0, lind);
        }
        else{
            s = s.substr(0, lind);
            s[s.length()-1]++;
            cout<<s;
        }
    }
    cout<<"\n";
    return 0;
}