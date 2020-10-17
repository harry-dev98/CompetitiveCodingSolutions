#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string str;
    cin>>t;
    while(t--){
        cin>>str;
        stack<char> S;
        for(char ch: str){
            if(S.empty() || ch == 'A')S.push(ch);
            else {
                S.pop();
            }
        }
        cout<<S.size()<<"\n";
    }
    return 0;
}