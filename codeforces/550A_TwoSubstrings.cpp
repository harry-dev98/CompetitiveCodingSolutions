#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    bool ans[3];
    ans[0] = 0;  ans[1] = 0; ans[2] = 0;
    int i=1;
    while(i<n){
        if((s[i-1] == 'A' && s[i] == 'B' && s[i+1] == 'A')||(s[i-1] == 'B' && s[i] == 'A' && s[i+1] == 'B') && ans[0] == 0){
            ans[0] = 1;
            i += 2;
        }
        else if(s[i-1] == 'A' && s[i] == 'B' && ans[1] == 0){
            ans[1] = 1;
            i++;
        }
        else if(s[i-1] == 'B' && s[i] == 'A' && ans[2] == 0){
            ans[2] = 1;
            i++;
        }
        i++;
    }
    cout<<((ans[1] && ans[2])||(ans[0] && (ans[1] || ans[2])) ?"YES":"NO")<<"\n";
    return 0;
}