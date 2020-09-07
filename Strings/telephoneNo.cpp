#include<bits/stdc++.h>
using namespace std;

#define SPEED ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


int main(){
    SPEED;
    int t, n;
    string s;
    bool ans;
    cin>>t;
    while(t--){
        ans = true;
        cin>>n>>s;
        if(n<11){
            ans = false;
        }
        else{
            if(n==11){
                if(s[0] != '8'){
                    ans=false;
                }
            }
            else{
                ans = false;
                for(int i=0; i<n-10; i++){
                    if(s[i] == '8'){
                        ans = true;
                        break;
                    }
                }
            }
        }
        cout<<(ans?"YES":"NO")<<"\n";
    }
    return 0;
}