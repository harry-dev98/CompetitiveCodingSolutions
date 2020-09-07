#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        int sum=0;
        string ans = "";
        int v;
        for(auto ch:s){
            v = (ch-'0');
            sum+=v;
            if(v%2){
                ans+=ch;
            }
        }
        if(ans.length()>1){
            cout<<ans.substr(0,2)<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }   
    }
    return 0;
}