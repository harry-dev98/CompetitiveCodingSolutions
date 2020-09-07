#include<bits/stdc++.h>
using namespace std;

bool isPali(string s){
    string rev = s;
    reverse(rev.begin(), rev.end());
    return rev==s;
    
}

int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int n = s.length();
        if(isPali(s)){
            char prev = s[0];
            bool ans=false;
            for(int i=1; i<n; i++){
                if(prev != s[i]){
                    char temp = s[i];
                    s[0] = temp;
                    s[i] = prev;
                    ans = true;
                    break;
                }
            }
            cout<<(ans?s:"-1");
        }
        else{
            cout<<s;
        }
        cout<<"\n";
    }
    return 0;
}