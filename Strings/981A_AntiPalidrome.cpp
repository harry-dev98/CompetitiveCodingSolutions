#include<bits/stdc++.h>
using namespace std;

bool isPali(string s){
    string r = s;
    reverse(r.begin(), r.end());
    return r==s;
}

int main(){
    string s;
    cin>>s;
    if(isPali(s)){
        char prev = s[0];
        int n = s.length();
        bool ans = false;
        for(int i=1; i<n; i++){
            if(s[i] != prev){
                ans=true;
                break;
            }
        }
        cout<<(ans?n-1:0);
    }
    else{
        cout<<s.length();
    }
    cout<<"\n";
    return 0;
}